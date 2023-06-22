
# system
Configuration files of my linux system

## config

Configuration files for some linux applications.
Some applications have standalone repositories like [neovimConfig](https://github.com/nishantHolla/neovimConfig)
and [awesomeConfig](https://github.com/nishantHolla/awesomeConfig)

## sis

sis (system interface service) is a collection of C++ libraries which perform small but essential
task that can be reused in multiple C++ applications.

### sisIO

sisIO is an input output library that performs input and output to console and log information to
a selected log file. It provides colorized output if the terminal supports ansi color codes.

### sisAuth

sisAuth is an authentication library that provides an interface to generate and compare
password hashes. The hashes generated are salted with [argon2](https://en.wikipedia.org/wiki/Argon2)
and hence can be used to hash and store passwords.
<br><br>
Argon2 package should be present in PATH in order to use this library.

### sisAuth

## setup

A setup script to link all config files and pull down other git repositories to the right locations.

### To install

- Clone this repository.

```bash
git clone https://github.com/nishantHolla/system.git
```

- Copy required config folders to required location or run the setup.sh script to link all config to
required locations. NOTE: the script will only create a symlink and does not copy any files or folders.

- Fullfill the requirements mentioned in individual READMEs.
