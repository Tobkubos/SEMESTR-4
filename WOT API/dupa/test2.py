import requests
import json

def get_clan_members(clan_id):
    url = "https://api.worldoftanks.eu/wot/clans/info/"
    params = {
        "application_id": "e5ebfe7a7df5498e28e61d230091cf09",
        "clan_id": clan_id,
        "fields": "members.account_id"
    }

    response = requests.get(url, params=params)

    if response.status_code == 200:
        data = response.json()
        if data and "data" in data and str(clan_id) in data["data"]:
            members = data["data"][str(clan_id)]["members"]
            # Pobieramy same ID graczy
            return [member["account_id"] for member in members]
        else:
            print(f"Brak danych o członkach klanu o id {clan_id}.")
            return []
    else:
        print(f"Błąd podczas pobierania danych dla klanu o id {clan_id}: {response.status_code}")
        return []

# Funkcja do zapisywania ID, każde na osobnej linii
def save_ids_to_file(ids, filename):
    with open(filename, 'a') as f:  # 'a' pozwala na dopisywanie
        for id in ids:
            f.write(f"{id},\n")

# Odczytanie clan ID z pliku JSON
with open("clan_ids2.json", "r") as f:
    clan_id_data = json.load(f)
    if isinstance(clan_id_data, list) and clan_id_data:
        for clan_id in clan_id_data:
            # Wywołanie funkcji pobierającej ID członków klanu
            clan_member_ids = get_clan_members(clan_id)

            if clan_member_ids:
                # Zapisanie ID do pliku tekstowego
                save_ids_to_file(clan_member_ids, "all_player_ids.json")
                print(f"ID członków klanu o id {clan_id} zapisane do pliku 'all_player_ids.csv'.")
            else:
                print(f"Brak danych o członkach dla klanu o id {clan_id}.")
    else:
        print("Nieprawidłowy format danych w pliku JSON lub brak danych.")