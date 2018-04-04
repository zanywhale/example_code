docker run -w /home/ -it dockername /bin/bash
# -v : mount host to docker
docker rm -v $(docker ps -a -q -f status=exited)
