import requests
import json
from pprint import pprint
import operator

dataitem = requests.get('https://fantasy.premierleague.com/drf/bootstrap-static')
data = dataitem.json()
#print(json.dumps(data, indent=2))
with open('data.json', 'w') as f:
    json.dump(data, f)

dreamteamers = {}

for i in data['elements']:
    if (150 < float(i['influence'])):
        result = i['id']
        dreamteamers[result] = i['now_cost']

sorted_dreamteamers = sorted(dreamteamers.items(), key=operator.itemgetter(1))

for i in data['elements']:
    for j,l in sorted_dreamteamers:
        if (i['id'] == j):
            print i['web_name']
print ""
for i in data['elements']:
    for j,l in sorted_dreamteamers:
        if (i['id'] == j):
            print i['form']
print ""
for i in data['elements']:
    for j,l in sorted_dreamteamers:
        if (i['id'] == j):
            print i['value_form']
print ""
for i in data['elements']:
    for j,l in sorted_dreamteamers:
        if (i['id'] == j):
            print i['threat']
print ""
for i in data['elements']:
    for j,l in sorted_dreamteamers:
        if (i['id'] == j):
            print i['minutes']
print ""
for i in data['elements']:
    for j,l in sorted_dreamteamers:
        if (i['id'] == j):
            print i['now_cost']
print ""
for i in data['elements']:
    for j,l in sorted_dreamteamers:
        if (i['id'] == j):
            print i['bps']
print ""
for i in data['elements']:
    for j,l in sorted_dreamteamers:
        if (i['id'] == j):
            print i['points_per_game']
