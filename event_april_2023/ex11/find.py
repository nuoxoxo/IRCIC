import json
from unicodedata import name
import requests


p = input('Enter the name of a Pokemon: ')
print(p)

url = ('https://pokeapi.co/api/v2/pokemon/')

def main(): 
    r = requests.get(url + p)
    status = r.status_code 
    if status != 200: 
        quit()
    else: 
        get_pokedex(status)
        

def get_pokedex(x): 
    print("status code: ", + x)
    response = requests.get(url).json()
    print(response)

if __name__ == '__main__':
    main() 

