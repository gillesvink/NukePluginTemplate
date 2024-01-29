# Example Dockerfile to showcase possibilities of prepping a dev container
# This file can be customized to include anything you would need on your MacOS ARM installation.

ARG NUKE_VERSION=15.0
FROM "ghcr.io/gillesvink/nukedockerbuild:${NUKE_VERSION}-macos-arm-latest"
RUN apt-get update && apt-get install -y git