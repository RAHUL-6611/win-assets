from bs4 import BeautifulSoup
import urllib.request as urllib2
import re

html_page = urllib2("https://simplywall.st/")
soup = BeautifulSoup(html_page)
images = []
for img in soup.findAll('img'):
    images.append(img.get('src'))

print(images)