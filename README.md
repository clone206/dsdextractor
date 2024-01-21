# dsdextractor

Simple and portable command-line program for extracting raw DSD from files. DSF and DFF are two file formats for containing [Direct Stream Digital](https://en.wikipedia.org/wiki/Direct_Stream_Digital) audio data. Most players and converters support both, but some only one.

## What it doesn't do

- convert DFF to DSF – see: [michaelburton/dsdunpack](https://github.com/michaelburton/dsdunpack)
- compress audio data with DST – I don't know any DST encoders for Linux, but [WavPack](https://wavpack.com) is a much better free software alternative
- convert DSD to PCM – WavPack does transparent DSD-PCM conversion as well; also: [this SoX fork by mansr](https://github.com/mansr/sox)
