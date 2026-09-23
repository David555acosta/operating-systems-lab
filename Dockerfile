
FROM gcc:latest AS builder-c

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    make \
    && rm -rf /var/lib/apt-lists/*

WORKDIR /src
COPY . .


RUN mkdir -p /app/apps-dotnet && \
    find . -name "*.csproj" | while read -r proj; do \
        dir=$(dirname "$proj"); \
        name=$(basename "$dir"); \
        echo "=== Compilando .NET project: $name desde $proj ==="; \
        dotnet publish "$proj" -c Release -o "/app/apps-dotnet/$name" || true; \
    done

FROM mcr.microsoft.com/dotnet/sdk:8.0 AS builder-dotnet

WORKDIR /src
COPY . .


RUN find . -name "*.csproj" -exec sh -c '\
      dir=$(dirname "$1"); \
      name=$(basename "$dir"); \
      echo "=== Compilando .NET project: $name ==="; \
      dotnet publish "$1" -c Release -o "/app/apps-dotnet/$name"; \
    ' _ {} \;


FROM mcr.microsoft.com/dotnet/sdk:8.0 AS final


RUN apt-get update && apt-get install -y \
    valgrind \
    gdb \
    && rm -rf /var/lib/apt-lists/*

WORKDIR /app


COPY --from=builder-c /src/binaries-c ./binaries-c/
COPY --from=builder-dotnet /app/apps-dotnet ./apps-dotnet/


RUN chmod +x /app/binaries-c/* || true

CMD ["bash"]