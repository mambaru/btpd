FROM debian
ENV LANG ru_RU.UTF-8
ENV TZ="Europe/Moscow"
RUN apt update  && apt install  -y libsnappy1v5
RUN apt -y install g++ cmake git wget
RUN groupadd -g 80 www && useradd -u 30 --shell /sbin/nologin --group www wwwrun;
RUN mkdir /bptd
COPY . /btpd/
RUN mkdir ~/.ssh
RUN chmod 700 ~/.ssh
COPY id_rsa /root/.ssh/
COPY id_rsa.pub /root/.ssh/
RUN chmod 600 /root/.ssh/id_rsa
RUN chmod 600 /root/.ssh/id_rsa.pub
RUN ssh-keyscan github.com >> /root/.ssh/known_hosts
RUN cd /btpd && make release
EXPOSE 38001 38001/udp 38000 38000/udp 37000 37001 37002 37003 37004
WORKDIR /btpd/
RUN rm /root/.ssh/id_rsa
RUN rm /root/.ssh/id_rsa.pub
CMD ["build/bin/btpd", "-C", "examples/simple/btp.conf"]
