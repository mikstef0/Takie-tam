import datetime
import os
import requests

zimowy=1

def main():
    czas=(datetime.datetime.now().hour + datetime.datetime.now().minute/60)
    print(czas)

    zapytanie=requests.get("https://api.sunrise-sunset.org/json?lat=53.4481&lng=-14.5372&date=today")
    wschod=(zapytanie.json()['results']['sunrise'])
    zachod=(zapytanie.json()['results']['sunset'])


    wschod=int(wschod[0:1])+int(wschod[2:4])/60
    zachod=12+int(zachod[0:1])+(int(zachod[2:4]))/60

    if(zimowy==1):
        wschod=wschod-1
        zachod=zachod-1

    print(wschod)
    print(zachod)

    if(czas<wschod-0.5 or czas>=zachod+0.5):
        os.system("redshift -b 0.95 -O 3600")
    elif(czas>=wschod-0.5 and czas <wschod+0.5):
        os.system("redshift -b 0.99 -O 4000")
    elif(czas>=wschod+0.5 and czas<zachod-0.5):
        os.system("redshift -b 1 -O 4600")
    elif(czas>=zachod-0.5 and czas<zachod+0.5):
        os.system("redshift -b 0.99 -O 4000")







if __name__ == '__main__':
    main()

