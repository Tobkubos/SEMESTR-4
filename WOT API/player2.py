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

def is_player_from_poland(player_info):
    # Sprawdź, czy język klienta gracza jest ustawiony na polski
    return player_info.get('client_language') == 'pl'

# Odczytanie listy identyfikatorów graczy z pliku JSON
with open("all_player_ids.json", "r") as f:
    player_ids = json.load(f)

# Pobieranie informacji o graczu i zapisywanie odpowiednich danych do listy
polish_players_info = []
for player_id in player_ids:
    player_info = get_player_info(player_id)
    if player_info:
        # Sprawdzenie czy gracz jest z Polski
        if is_player_from_poland(player_info['data'][str(player_id)]):
            # Przetwarzanie danych gracza
            polish_players_info.append({
                "account_id": player_id,
                "global_rating": player_info['data'][str(player_id)]['global_rating'],
                "last_battle_time": player_info['data'][str(player_id)]['last_battle_time']
            })
            print(f"Informacje o graczu o id {player_id} pobrane.")
        else:
            print(f"Gracz o id {player_id} nie jest z Polski.")
    else:
        print(f"Brak danych dla gracza o id {player_id}.")

# Zapisanie informacji o graczach z Polski do pliku JSON
save_to_json(polish_players_info, "polish_players_info.json")
print("Informacje o graczach z Polski zapisane do pliku 'polish_players_info.json'.")