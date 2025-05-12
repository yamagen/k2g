# README.md

## K2G: Classical Japanese (Koten) Morphological/Gloss Analyzer

### Description

KogoGloss is a rule-based morphological analysis system for Classical Japanese. It is built upon manually curated phrase gloss data from texts such as _Ise Monogatari_ and _Tosa Nikki_, aiming to produce high-accuracy, context-sensitive segmentation and grammatical annotation.

### Features

- Phrase-level morphological analysis with support for auxiliary verbs and classical particles
- Supports Leipzig Glossing Rules
- Accurate tagging for classical expressions such as `PST.REP`, `HON`, `COP`, etc.
- Designed for linguists, digital humanities researchers, and classical Japanese educators

### Data Sources

- AEAD (An Expression A Day)
- Ise Monogatari annotated glosses
- Tosa Nikki annotated glosses

### Output Format

JSON-based structure:

```json
[
  {
    "surface": "詠め",
    "base": "詠む",
    "gloss": "compose",
    "features": ["PST"]
  },
  { "surface": "る", "gloss": "ATTR", "features": ["attributive"] },
  { "surface": "歌", "gloss": "poem", "features": ["noun"] }
]
```

### Goals

- Enable educational and research uses of annotated Classical Japanese corpora
- Provide a foundation for machine-assisted translation and annotation

### License

To be determined (possibly MIT or Creative Commons BY-SA).

### Author

Hilo Yamamoto and collaborators.

---

（このREADMEは今後の実装に応じて適宜拡張されます）
