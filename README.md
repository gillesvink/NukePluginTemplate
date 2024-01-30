# 🎨 NukePluginTemplate

This repository serves as a starting point for Nuke plugin development.
It has everything set-up so you can start right away with developing (using dev containers).

Additionally, it includes a [CI/CD](.github/workflows/build.yaml) pipeline for building Nuke plugins for Linux, MacOS and Windows.

Just [fork](https://github.com/gillesvink/NukePluginTemplate/fork), clone or [download](https://github.com/gillesvink/NukePluginTemplate/archive/refs/heads/main.zip) and start :)

## Requirements
Install:
* [Docker](https://docs.docker.com/get-docker/)
* [Visual Studio Code](https://code.visualstudio.com/)

Then get the [Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers) extension from Microsoft.

If you prefer IntelliJ, that should also be possible: [IntelliJ Docs](https://www.jetbrains.com/help/idea/connect-to-devcontainer.html)

## Getting started
For an extended guide on how to use this and getting started, visit my blog:

### [The easiest and quickest way of developing and compiling Nuke plugins](https://gillesvink.com/the-easiest-and-quickest-way-of-developing-and-compiling-nuke-plugins/)

<a href="https://gillesvink.com/the-easiest-and-quickest-way-of-developing-and-compiling-nuke-plugins/"><img src="https://gillesvink.com/assets/resources/guide_to_setting_up_development_environment/thumbnail.jpg" alt="drawing" width="30%"/></a>

## Includes
`CMakeLists.txt` has been setup to build the Multiply node. It will build to the `build` folder (or what you've specified) and write inside there to the `lib` folder. (`/build/lib/Multiply.(dll | .so)`)

## Development Containers
It includes a setup for Development Containers.

The images used are from my other repository [NukeDockerBuild](https://github.com/gillesvink/NukeDockerBuild) and include all necessary dependencies and installations. For more info, check out that repository. These images will be automatically generated based on all available Nuke versions.

These images are built for the purpose so that you don't have to install anything yourself. (*GCC, Nuke, OpenGL lib's etc.*)

## Configuration
Within the `devcontainer.json` you can specify which Nuke version you would like to use for developing.

* [devcontainer.json](./.devcontainer/devcontainer.json)

This can be done by altering the `NUKE_VERSION` argument. By default it is `15.0`, but it can be anything that is currently available starting from 13.0+.
```json
"build": {
    "dockerfile": "Dockerfile",
    "args": {
      "NUKE_VERSION": "15.0"
    }
}
```
Also here is where you can specify additional extensions needed for your development environment. By default everything is included for C++ based development.

If you need anything to be set-up additionally, you can alter the Dockerfiles that are in the same folder with instructions you do need. By default it installs `git`.

When you open the devcontainer in VSCode, you will be prompted with the environment you'd like to create. The options are: `linux`, `macos-x86` and `macos-arm`. This will be the environment where you'd build your plugins locally to.

If you use the MacOS options, [make sure you’ve read and understood the Xcode license agreement](https://www.apple.com/legal/sla/docs/xcode.pdf).

And by using the containers, you will also agree to the [Foundry EULA](https://www.foundry.com/eula).

## CI/CD
It includes an automatic build pipeline for both Linux and Windows using Github Actions. This serves as a starting point and could be optimized by for example only building Windows on a tag change. The config for this file can be found at [.github/workflows/build.yaml](.github/workflows/build.yaml)

## And...
Have fun developing! 🛠️
