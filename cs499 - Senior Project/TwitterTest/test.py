from TwitterAPI import TwitterAPI
import csv

CONSUMER_KEY = 'AKxFaJPHG8i4DyZqkp98OH7Ua'
CONSUMER_SECRET = '2lZPp1S3yEdRt3VvfyaTjgCec03QLOFTpHBujFdImit2IxWRv4'
OAUTH_TOKEN = '718577287570935808-ymw2pMC7d8wf6Pu25AjtlB6L2e5Lbgg'
OAUTH_TOKEN_SECRET = 'h1Z7Yv7H2Ew0H01nr1NHYgULrcQcnLVRzScVRR8eC6uh5'

api = TwitterAPI(CONSUMER_KEY, CONSUMER_SECRET, OAUTH_TOKEN, OAUTH_TOKEN_SECRET)

TRACK_TERM = 'the'

data = api.request('statuses/filter', {'track': TRACK_TERM})

with open('newData.csv', 'w', encoding='utf8') as csvfile:
    fieldnames = ['', 'text', 'id', 'user name', 'screen name', 'description']
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)

    writer.writeheader()
    i = 1
    for item in data:
        if 'limit' in item:
            print()
        else:
            # print('Text: ' + item['text'] if 'text' in item else "Text")
            # print('ID: ' + str(item['id']) if 'id' in item else "Id")
            # print('User Name: ' + item['user']['name'] if 'name' in item['user'] else "User Name")
            # print('User Screen Name: ' + item['user']['screen_name'] if 'screen_name' in item['user'] else "Screen Name")
            # print('User Description: ' + str(item['user']['description']) if 'description' in item[
            #     'user'] else "Description")
            # print()
            try:
                if 'RT' not in item['text']:
                    writer.writerow({'': i, 'text': item['text'] if 'text' in item else "",
                                     'id': str(item['id']) if 'id' in item else "",
                                     'user name': item['user']['name'] if 'name' in item['user'] else "",
                                     'screen name': item['user']['screen_name'] if 'screen_name' in item['user'] else "",
                                     'description': str(item['user']['description']) if 'description' in item['user'] else ""})
                    i += 1
            except UnicodeEncodeError as e:
                print(e)
