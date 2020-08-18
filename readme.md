Teeworlds Bridge ![GitHub Actions](https://github.com/gerdoe-jr/teeworlds-bridge/workflows/Build/badge.svg)
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
====================

```
sv_discord_token "token"
sv_discord_server "15351155461346"
sv_discord_channel "12345567899765"
```

Invite bot on your Discord Server and launch server. Good! Now you can chat via Discord.

---
