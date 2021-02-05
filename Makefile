export UID=$(shell id -u)
export GID=$(shell id -g)

.PHONY: docker-prod

dev:
	@$(MAKE) --no-print-directory dev-impl

dev-impl:
	@nodemon

dev-nowatch:
	@scripts/build_locally.sh

dev-asan:
	@CMAKE_BUILD_TYPE=ASAN $(MAKE) dev

dev-msan:
	@CMAKE_BUILD_TYPE=MSAN $(MAKE) dev

dev-tsan:
	@CMAKE_BUILD_TYPE=TSAN $(MAKE) dev

dev-ubsan:
	@CMAKE_BUILD_TYPE=UBSAN $(MAKE) dev

dev-clang-analyzer:
	@USE_CLANG_ANALYZER=1 scripts/build_locally.sh

prod:
	@CMAKE_BUILD_TYPE=Release scripts/build_locally.sh

profile:
	@CMAKE_BUILD_TYPE=RelWithDebInfo scripts/build_locally.sh

benchmarks:
	@$(MAKE) --no-print-directory benchmarks-impl

benchmarks-impl:
	@nodemon --config nodemon.benchmarks.json

benchmarks-nowatch:
	@scripts/benchmarks.sh

format:
	@scripts/format.sh

clang-tidy:
	@scripts/clang-tidy.sh



# "Builder" docker container

# Pulls "Builder" docker container from Docker Hub
docker-builder-pull:
	./scripts/docker_builder_image_pull.sh

# Pushes "Builder" docker container to Docker Hub
docker-builder-push:
	./scripts/docker_builder_image_push.sh

# Builds "Builder" docker container
docker-builder-build:
	./scripts/docker_builder_image_build.sh

# Updates (pull-build-push) "Builder" docker container
docker-builder-update: docker-builder-pull docker-builder-build docker-builder-push



# Development in "Builder" docker container

## Builds and runs "Builder" container in dev mode
docker-dev: docker-builder-build docker-dev-run

## Runs "Builder" container in dev mode
docker-dev-run:
	./scripts/docker_builder_image_run.sh make dev



# Production in "Builder" docker container

## Builds and runs "Builder" container in prod mode
docker-prod: docker-builder-build docker-prod-run

## Runs "Builder" container in prod mode
docker-prod-run:
	./scripts/docker_builder_image_run.sh make prod


# Checks if attempted release version is valid
check-release-version:
	scripts/check_release_version.sh
