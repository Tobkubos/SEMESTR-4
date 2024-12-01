import requests

url = "https://api.worldoftanks.eu/wot/account/info/"
params = {
    "application_id": "e5ebfe7a7df5498e28e61d230091cf09",
    "account_id": "563250077",
    "fields": "client_language"
}

response = requests.get(url, params=params)

if response.status_code == 200:
    data = response.json()
    print("Client Language:", data['data']['563250077']['client_language'])
else:
    print(f"Błąd podczas pobierania danych: {response.status_code}")