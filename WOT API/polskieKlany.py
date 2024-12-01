import requests
import json
import re

# Funkcja pobierająca szczegóły klanów w porcjach
def get_clan_details(clan_ids, chunk_size=1):
    url = "https://api.worldoftanks.eu/wot/clans/info/"
    all_details = {"data": {}}

    for i in range(0, len(clan_ids), chunk_size):
        chunk = clan_ids[i:i + chunk_size]
        params = {
            "application_id": "e5ebfe7a7df5498e28e61d230091cf09",
            "clan_id": ",".join(map(str, chunk)),
            "fields": "description,tag,name"
        }

        response = requests.get(url, params=params)

        if response.status_code == 200:
            data = response.json()
            if "data" in data:
                all_details["data"].update(data["data"])
        else:
            print(f"Błąd podczas pobierania szczegółów klanów dla porcji {chunk}: {response.status_code}")

    return all_details

# Funkcja analizująca opis klanu
def analyze_clan_description(clan_details):
    polish_keywords = [
        "Polska", "Polski", "Polskiego", 
        "witaj", "witamy", "zapraszamy", 
        "dywizja", 
        "bitwa", "bitwy", 
        "twierdza", "tw", 
        "sojusz", 
        "gracze", "graczy", 
        "rekrutacja", "rekrutacji", 
        "kontakt", "kontaktu", 
        "rezerwy", 
        "złoto", "zloto"
    ]

    description = clan_details.get("description", "")
    
    # Tworzymy wzorzec z listy słów kluczowych
    keyword_pattern = r'\b(?:' + '|'.join(map(re.escape, polish_keywords)) + r')\b'
    
    # Sprawdzamy, czy jakiekolwiek słowo kluczowe występuje w opisie
    if re.search(keyword_pattern, description, re.IGNORECASE):
        return True, description
    return False, description

# Funkcja zapisująca dane do pliku JSON
def save_to_json(data, filename):
    with open(filename, 'w') as f:
        json.dump(data, f, indent=4)

# Główna logika programu
if __name__ == "__main__":
    # Odczytanie ID klanów z pliku JSON
    try:
        with open("clan_ids2.json", "r") as f:
            clan_ids = json.load(f)
    except FileNotFoundError:
        print("Plik 'clan_ids2.json' nie istnieje.")
        clan_ids = None

    if clan_ids:
        identified_clans = []
        for clan_id in clan_ids:
            # Pobranie szczegółów jednego klanu
            clan_details = get_clan_details([clan_id], chunk_size=1)
            if clan_details and "data" in clan_details:
                for clan_key, details in clan_details["data"].items():
                    # Analiza opisu klanu
                    match, description = analyze_clan_description(details)
                    if match:
                        identified_clans.append({
                            "clan_id": clan_key,
                            "tag": details.get("tag"),
                            "name": details.get("name"),
                            "description": description
                        })
                        print(f"Klan {details.get('tag')} ({clan_key}) pasuje do wzorca.")
                    #else:
                        #print(f"Klan {details.get('tag')} ({clan_key}) nie pasuje do wzorca.")
            else:
                print(f"Błąd pobierania danych dla klanu {clan_id}.")

        # Zapisanie wyników do pliku JSON
        save_to_json(identified_clans, "polish_clans.json")
        print("Zidentyfikowane polskie klany zapisane do pliku 'polish_clans.json'.")
    else:
        print("Brak danych o klanach do analizy.")
