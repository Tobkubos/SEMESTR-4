import requests
import json

def get_clan_members(clan_id):
    url = "https://api.worldoftanks.eu/wot/clans/info/"
    params = {
        "application_id": "e5ebfe7a7df5498e28e61d230091cf09",
        "clan_id": clan_id,
        "fields": "members",
        "members_key": "id"
    }

    response = requests.get(url, params=params)

    if response.status_code == 200:
        data = response.json()
        return data
    else:
        print(f"Błąd podczas pobierania danych dla klanu o id {clan_id}: {response.status_code}")
        return None

def save_to_json(data, filename):
    try:
        with open(filename, 'r') as f:
            existing_data = json.load(f)
    except FileNotFoundError:
        existing_data = []

    for clan_id, clan_data in data.items():
        if 'members' in clan_data:
            player_ids = [member_id for member_id in clan_data['members']]
            existing_data.extend(player_ids)

    with open(filename, 'w') as f:
        json.dump(existing_data, f, indent=4)
# Odczytanie clan ID z pliku JSON
with open("clan_ids2.json", "r") as f:
    clan_id_data = json.load(f)
    if isinstance(clan_id_data, list) and clan_id_data:
        for clan_id in clan_id_data:
            # Wywołanie funkcji pobierającej informacje o członkach klanu
            clan_members_data = get_clan_members(clan_id)

            if clan_members_data:
                # Zapisanie tylko identyfikatorów graczy do pliku JSON
                save_to_json(clan_members_data['data'], "all_player_ids.json")
                print(f"Informacje o członkach klanu o id {clan_id} zapisane do pliku 'all_player_ids.json'.")
            else:
                print(f"Brak danych o członkach dla klanu o id {clan_id}.")
    else:
        print("Nieprawidłowy format danych w pliku JSON lub brak danych.")