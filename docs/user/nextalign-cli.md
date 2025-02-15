# Nextalign CLI

Nextalign CLI is a viral genome sequence alignment tool for command line. It uses the same algorithm that is used in [Nextclade Web](nextclade-web) and [Nextclade CLI](nextclade-cli).

You can learn more about the algorithm in the [Algorithm: Sequence alignment](algorithm.html#sequence-alignment) section.

### Installation (with docker)

Container images are available at Docker Hub: 🐋 [nextstrain/nextalign](https://hub.docker.com/repository/docker/nextstrain/nextalign)

Pull and run the latest version with:

```bash
docker pull nextstrain/nextalign:latest
docker run -it --rm nextstrain/nextalign:latest nextalign --help
```

Pull and run a specific version with:

```bash
docker run -it --rm nextstrain/nextalign:1.0.0 nextalign --help
```

Don't forget to mount necessary volumes to be able to supply the data inside the container and to access the results.

### Installation (local)

#### Download manually

You can download the latest version of Nextalign CLI for your platform using one of these direct links:

- ⬇️ [Nextalign for Linux (x86_64)](https://github.com/nextstrain/nextalign/releases/latest/download/nextalign-Linux-x86_64)
- ⬇️ [Nextalign for macOS (Intel, x86_64)](https://github.com/nextstrain/nextalign/releases/latest/download/nextalign-MacOS-x86_64)
- ⬇️ [Nextalign for macOS (Apple Silicon, ARM64)](https://github.com/nextstrain/nextalign/releases/latest/download/nextalign-MacOS-arm64)

All versions and their release notes are available on 🐈 [Github Releases](https://github.com/nextstrain/nextclade/releases).

These executables are self-contained and don't require any dependencies. They can be renamed and moved freely. It is convenient to rename the executable to `nextclade` and to move to one of the directories included in system `$PATH`, so that it's available from any directory in the console.

> ⚠️ Note that macOS executables are not currently signed with a developer certificate (it requires maintaining a paid Apple developer account). Recent versions of macOS might refuse to run the executable. Before invoking Nextalign on command line, follow these steps to add Nextalign to the exclude list:
> <a target="_blank" rel="noopener noreferrer" href="https://support.apple.com/guide/mac-help/open-a-mac-app-from-an-unidentified-developer-mh40616/mac">
macOS User Guide: Open a Mac app from an unidentified developer</a>, and check <a target="_blank" rel="noopener noreferrer" href="https://support.apple.com/en-us/HT202491">
Security settings</a>. Refer to the latest macOS documentation if none of this works.

> ⚠️ Native Windows executables are not available at this time. Windows users can try one of the following:
>
> - Download the Linux executable (see above) and run it under [Windows Subsystem for Linux (WSL)](https://docs.microsoft.com/en-us/windows/wsl/install-win10)
> - Use [Docker container image](#installation-with-docker)
> - Rent a Linux machine, for example at a cloud compute provider or on premises of your organization or university
>


#### Download from command line

The following commands can be used to download Nextalign from command line, from shell scripts and inside dockerfiles:

<p>
<details>
<summary>
🐧 Linux x86_64 (click to expand)
</summary>

Download latest version:

```bash
curl -fsSL "https://github.com/nextstrain/nextclade/releases/latest/download/nextalign-Linux-x86_64" -o "nextalign" && chmod +x nextalign
```

Download specific version:

```bash
NEXTALIGN_VERSION=1.0.0 curl -fsSL "https://github.com/nextstrain/nextclade/releases/download/nextalign-${NEXTALIGN_VERSION}/nextalign-Linux-x86_64" -o "nextalign" && chmod +x nextalign
```

</details>
</p>

<p>
<details>
<summary>
🍏 macOS Intel (click to expand)
</summary>

Download latest version:

```bash
curl -fsSL "https://github.com/nextstrain/nextclade/releases/latest/download/nextalign-MacOS-x86_64" -o "nextalign" && chmod +x nextalign
```

Download specific version:

```bash
NEXTALIGN_VERSION=1.0.0 curl -fsSL "https://github.com/nextstrain/nextclade/releases/download/nextalign-${NEXTALIGN_VERSION}/nextalign-MacOS-x86_64" -o "nextalign" && chmod +x nextalign
```

</details>
</p>

<p>
<details>
<summary>
🍎 macOS Apple Silicon (click to expand)
</summary>

Download latest version:

```bash
curl -fsSL "https://github.com/nextstrain/nextclade/releases/latest/download/nextalign-MacOS-arm64" -o "nextalign" && chmod +x nextalign
```

Download specific version:

```bash
NEXTALIGN_VERSION=1.0.0 curl -fsSL "https://github.com/nextstrain/nextclade/releases/download/nextalign-${NEXTALIGN_VERSION}/nextalign-MacOS-arm64" -o "nextalign" && chmod +x nextalign
```

</details>
</p>


Native Windows executables are not available at this time. Windows users can try one of the following:

- Downloading and running Linux executable from [Windows Subsystem for Linux (WSL)](https://docs.microsoft.com/en-us/windows/wsl/install-win10)
- Running docker container (see below)
- Renting a Linux machine, for example at any cloud compute provider

### Usage

Refer to help prompt for usage of Nextalign:

```bash
nextalign --help
```

## Quick Example

1. Download the example SARS-CoV-2 data files from [GitHub](https://github.com/nextstrain/nextclade/tree/master/data/sars-cov-2)
    (You can also try other viruses in the `data/` directory)

2. Run:

   ```bash
   nextalign \
    --sequences=data/sars-cov-2/sequences.fasta \
    --reference=data/sars-cov-2/reference.fasta \
    --genemap=data/sars-cov-2/genemap.gff \
    --genes=E,M,N,ORF1a,ORF1b,ORF3a,ORF6,ORF7a,ORF7b,ORF8,ORF9b,S \
    --output-dir=output/ \
    --output-basename=nextalign
   ```

   Add `--verbose` flag to show more information in the console. Add `--include-reference` flag to also write gap-stripped reference sequence and peptides into outputs.

3. Find the output files in the `output/` directory:

    - `nextalign.aligned.fasta` - aligned input sequences
    - `nextalign.gene.<gene_name>.fasta` - aligned peptides corresponding to each gene

## What's next?

Congratulations, You have learned how to use Nextalign CLI!

Going further, you might want to learn about the science behind the Nextalign internals in the [Algorithm](algorithm) section. The required input data is described in [Input files](input-files) section. And produced files are described in [Output files](output-files) section.

For a more convenient online tool, check out [Nextclade Web](nextclade-web).

Nextclade is an open-source project. We welcome ideas and contributions. Head to our [GitHub repository](https://github.com/nextstrain/nextclade) if you want to obtain source code and contribute to the project.
