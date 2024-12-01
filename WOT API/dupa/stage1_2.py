import requests
import json

def get_clan_info(clan_id):
    url = "https://api.worldoftanks.eu/wot/clans/info/"
    params = {
        "application_id": "e5ebfe7a7df5498e28e61d230091cf09",
        "clan_id": clan_id,
    }

    response = requests.get(url, params=params)

    if response.status_code == 200:
        data = response.json()
        return data
    else:
        print(f"Błąd podczas pobierania danych dla klanu o id {clan_id}: {response.status_code}")
        return None

def save_to_json(data, filename):
    with open(filename, 'w') as f:
        json.dump(data, f, indent=4)

def is_clan_from_poland(clan_info):
    # Sprawdź, czy język klanu jest ustawiony na polski
    return clan_info.get('client_language') == 'pl'

# Odczytanie listy identyfikatorów klanów z pliku JSON
with open("clan_ids2.json", "r") as f:
    clan_ids = json.load(f)

# Pobieranie informacji o klanie i zapisywanie odpowiednich danych do listy
polish_clans_info = []
for clan_id in clan_ids:
    clan_info = get_clan_info(clan_id)
    if clan_info:
        # Sprawdzenie czy klan jest z Polski
        if is_clan_from_poland(clan_info['data'][str(clan_id)]):
            # Przetwarzanie danych klanu
            polish_clans_info.append({
                "clan_id": clan_id,
                "clan_name": clan_info['data'][str(clan_id)]['clan_name'],
                # Tutaj możesz dodać inne potrzebne informacje o klanie
            })
            print(f"Informacje o klanie o id {clan_id} pobrane.")
        else:
            print(f"Klan o id {clan_id} nie jest z Polski.")
    else:
        print(f"Brak danych dla klanu o id {clan_id}.")

# Zapisanie informacji o klanach z Polski do pliku JSON
save_to_json(polish_clans_info, "polish_clans_info.json")
print("Informacje o klanach z Polski zapisane do pliku 'polish_clans_info.json'.")