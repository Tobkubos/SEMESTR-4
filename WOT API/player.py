import requests
import json

def get_player_info(player_id):
    url = "https://api.worldoftanks.eu/wot/account/info/"
    params = {
        "application_id": "e5ebfe7a7df5498e28e61d230091cf09",
        "account_id": player_id,
    }

    response = requests.get(url, params=params)

    if response.status_code == 200:
        data = response.json()
        return data
    else:
        print(f"Błąd podczas pobierania danych dla gracza o id {player_id}: {response.status_code}")
        return None

def save_to_json(data, filename):
    with open(filename, 'w') as f:
        json.dump(data, f, indent=4)

# Odczytanie listy identyfikatorów graczy z pliku JSON
with open("all_player_ids.json", "r") as f:
    player_ids = json.load(f)

# Pobieranie informacji o graczu i zapisywanie ich do jednego pliku JSON
players_info = []
for player_id in player_ids:
    player_info = get_player_info(player_id)
    if player_info:
        players_info.append(player_info)
        print(f"Informacje o graczu o id {player_id} pobrane.")
    else:
        print(f"Brak danych dla gracza o id {player_id}.")

# Zapisanie wszystkich informacji o graczach do jednego pliku JSON
save_to_json(players_info, "players_info.json")
print("Wszystkie informacje o graczach zapisane do pliku 'players_info.json'.")