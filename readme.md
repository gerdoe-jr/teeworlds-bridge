Teeworlds Bridge
================

Build
=====

Linux
-----

You need standard [libraries](https://github.com/teeworlds/teeworlds) and [Aegis.cpp](https://github.com/zeroxs/aegis.cpp) for this.

```
git clone https://github.com/gerdoe-jr/teeworlds-bridge
cd teeworlds-bridge
mkdir build && cd build
cmake ..
make
```
---

Configure own server
--------------------

```
sv_discord_token "YOUR_BOT'S_TOKEN"
sv_discord_channel "12345567899765" # unused
```

Invite bot on your Discord Server and launch server. After this, write `here!` in necessary channel. Good! Now you can chat via Discord.

---
