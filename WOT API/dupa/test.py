import requests
import json

def get_clan_ratings():
    url = "https://api.worldoftanks.eu/wot/clanratings/top/"
    params = {
        "application_id": "e5ebfe7a7df5498e28e61d230091cf09",
        "rank_field": "fort_elo_rating_10",
        "language": "pl",
        "fields": "clan_id,clan_tag",
        "limit": 999
    }

    response = requests.get(url, params=params)

    if response.status_code == 200:
        data = response.json()
        return data
    else:
        print("Błąd podczas pobierania danych:", response.status_code)
        return None

def extract_clan_ids(data):
    if "data" in data:
        clan_data = data["data"]
        clan_ids = [clan["clan_id"] for clan in clan_data]
        return clan_ids
    else:
        print("Brak danych o klanach w odpowiedzi.")
        return None

def save_to_json(data, filename):
    with open(filename, 'w') as f:
        json.dump(data, f, indent=4)

# Wywołanie funkcji pobierającej dane
clan_ratings_data = get_clan_ratings()

if clan_ratings_data:
    # Wyodrębnienie clan_id z danych
    clan_ids = extract_clan_ids(clan_ratings_data)
    
    if clan_ids:
        # Zapisanie clan_id do pliku JSON
        save_to_json(clan_ids, "clan_ids2.json")
        print("clan_id zapisane do pliku 'clan_ids.json'.")
else:
    print("Brak danych do zapisania.")