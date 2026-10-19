# Mulberry
## Building
There are a bunch of requirements needed in order to build, but there's a `shell.nix` file for those using Nix!

The `make` command installs multiple versions of Qt for you (for compiling to different platforms)

- `make debug` creates a debug desktop version at `out/Debug`
- `make desktop` creates a release desktop version at `out/Desktop`
- `make android` creates a release android apk at `out/Android.apk`
- `make release` runs `make desktop` and `make android`

### Android
If it ever complains about signatures, just uninstall the old app and try installing your version again.

`./run-android.sh` can be used for easily and quickly installing the built app onto your device.
Run `./run-android.sh --help` for help.
For your convenience, the below command uses that file to install, run and display logs for the app.
```
./run-android.sh i r l
```

### Linting
If your linter ever gets annoyed at you, run this *after having built for debug*;
```sh
cp build/debug/compile_commands.json compile_commands.json
```

and it should *hopefully* fix itself (maybe reload too)
