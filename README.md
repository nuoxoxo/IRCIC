__test list__
- todo...
- <kbd>RUN</kbd> docker exec -it wordpress ps aux | grep 'php'
- <kbd>RUN</kbd> docker exec -it wordpress php -v
- <kbd>RUN</kbd> docker exec -it wordpress php -m
- <kbd>TRY</kbd> `https://127.0.0.1`
- <kbd>RUN</kbd> docker exec -it mariadb mysql -u root
  - <kbd>SQL</kbd> show databases;

__needed at EVAL__  
```sh
# .env

DOMAIN_NAME=nuxu.42.fr

DB_NAME=wordpress
DB_ROOT=rootpass
DB_USER=wpuser
DB_PASS=wppass
```
__deprecated, snapshot 7__  
```sh
# .env

DOMAIN_NAME=nuxu.42.fr

CERT_=./requirements/tools/nuxu.42.fr.crt
KEY_=./requirements/tools/nuxu.42.fr.key

DB_NAME=wordpress
DB_ROOT=rootpass
DB_USER=wpuser
DB_PASS=wppass
```
