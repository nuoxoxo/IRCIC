in: &nbsp; `~/project/srcs/requirements/tools`

do:
```
rm *.pem
mkcert nuxu.42.fr && \
mv nuxu.42.fr-key.pem nuxu.42.fr.key && \
mv nuxu.42.fr.pem nuxu.42.fr.crt
```

then in: &nbsp; `~/demo_docker-compose`

do:
```
docker-compose up -d
```
