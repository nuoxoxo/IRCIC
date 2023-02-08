in: &nbsp; `~/project/srcs/requirements/tools`

do:
```
rm *.pem
mkcert nuoxoxo.42.fr && \
mv nuoxoxo.42.fr-key.pem nuoxoxo.42.fr.key && \
mv nuoxoxo.42.fr.pem nuoxoxo.42.fr.crt
```

then in: &nbsp; `~/demo_docker-compose`

do:
```
docker-compose up -d
```
