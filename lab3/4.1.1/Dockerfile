FROM gcc:4.9
RUN apt-get update
RUN apt-get install -y vim nano htop
COPY codigo.c /tmp
WORKDIR /tmp
RUN gcc -o prog codigo.c
RUN useradd aluno
RUN chown root prog
RUN chmod 4755 /tmp/prog
RUN rm codigo.c
USER aluno
ENTRYPOINT ["/bin/bash"]