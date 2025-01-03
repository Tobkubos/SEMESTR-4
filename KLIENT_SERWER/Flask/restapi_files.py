import os
import json
from flask import Flask, request
from flask import make_response

app = Flask(__name__)

config = {
    'filedir': os.path.join(os.curdir, 'files')
}

# Statyczna informacja o aplikacji
@app.route('/')
def root():
    return "Sample REST API flask application!"


#Uzyskanie zawartości katalogu (w formie text/json)
@app.route('/files')
def files():

    files = os.listdir(config['filedir'])

    return json.dumps(files)

#Uzyskanie zawartości pliku (w formie text/plain)
@app.route('/files/<filename>')
def file_get(filename):
    # Kompozycja ścieżki do wskazanego pliku.
    filepath = os.path.join(config['filedir'], filename)
    inp = open(filepath, 'rt')
    with inp:
        # Odczytany plik jest reprezentowany przez listę wierszy zakończonych znakami \n
        # Należy go zamienić na jeden ciąg znaków.
        response = make_response("".join(inp.readlines()))
        # Odpowiedź zwracana jest w formie czystego tekstu
        response.mimetype = 'text/plain'
        return response
        
# Zmiana zawartości pliku
@app.route('/files/<filename>', methods = ['POST'])
def file_post(filename):
    filebody = request.get_data(as_text=True)
    filepath = os.path.join(config['filedir'], filename)
    out = open(filepath, 'wt')
    with out:
        out.writelines(filebody)

        return {"Status": "OK"}