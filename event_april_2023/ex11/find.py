import json
import requests


p = input('Enter the name of a Pokemon: ')

response = requests.get(f'https://pokeapi.co/api/v2/pokemon/{p.lower()}')
# print(response.status_code)

if response.status_code == 404:
    print('connection error. please verify your choice of pokemon. ')
    exit()
res = response.json()
#print(type(res))

print('Name:', p.capitalize())
print('Abilities:')
for key in res['abilities']:
    print('-', key['ability']['name'].capitalize())



