# Finding non-binary SNP candidates

The [NCBI](http://www.ncbi.nlm.nih.gov/) has, amongst other things, a public
database of single nucleotide polymorphisms (SNPs). We made a tool that
searches this database for non-binary SNP candidates for various purposes.

## Installation
Install the [expat](http://expat.sourceforge.net/) development files:

    apt-get install libexpat1-dev

Compile the program:

    make

## Usage
To run the program:

- Get one of the files from
  [this](ftp://ftp.ncbi.nih.gov/snp/organisms/human_9606_b142_GRCh37p13/genotype/)
  location.
- If we assume that the downloaded file is named `gt_chrXX.xml.gz`, use
  the following command to find the SNP candidates:

      zcat gt_chrXX.xml.gz | ./snp <threshold> > output.txt

The `treshold` specifies the minimum allele frequency (in
percentages). If this option is omitted, the threshold defaults to 0. By
increasing this variable the amount of output can be greatly reduced, setting
it to 1 or higher is recommended.

Although we have not tested this program on files related to other species, we
see no reason why it should not work. To find input files for other species, go
[here](ftp://ftp.ncbi.nih.gov/snp/organisms/), select one of the directories
and choose the genotype subdirectory (if present).

When running multiple sessions with different thresholds, we recommend
decompressing the downloaded file first and running:

      ./snp <treshold> < gt_chrXX.xml > output.txt

Inspired by this research, we also looked into a related topic, the degradation
of [methylated nucleotides](https://git.lumc.nl/j.f.j.laros/cpg).
