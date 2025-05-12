# Dictionary File Specification (dictionary-en.md)

## Overview

This document describes the structure and purpose of the `dictionary.json` file used in the `k2g` project for classical Japanese morphological analysis.

---

## File Format

- Format: JSON
- Structure: Array of entries
- Encoding: UTF-8

---

## Sample Template

```json
[
  {
    "surface": "けり",
    "base": "けり",
    "gloss": "PST.REP",
    "features": ["aux", "past", "reportative"]
  },
  {
    "surface": "なり",
    "base": "なり",
    "gloss": "COP",
    "features": ["aux", "copula"]
  },
  {
    "surface": "を",
    "base": "を",
    "gloss": "ACC",
    "features": ["particle", "case"]
  },
  {
    "surface": "恋ひ",
    "base": "恋ふ",
    "gloss": "to long for",
    "features": ["verb", "stem"]
  },
  {
    "surface": "人",
    "base": "人",
    "gloss": "person",
    "features": ["noun"]
  }
]
```

---

## Field Descriptions

| Key        | Description                                               |
| ---------- | --------------------------------------------------------- |
| `surface`  | The surface form as it appears in the text                |
| `base`     | The base or lemma form (dictionary form)                  |
| `gloss`    | The gloss string or abbreviation representing its meaning |
| `features` | List of part-of-speech and grammatical function labels    |

---

## Notes

- Each entry corresponds to one surface form. Compound expressions should be split into component entries when possible.
- The label system for `features` will be defined in a separate `features.json` file.
- This dictionary file must be saved in UTF-8 encoding.
- Additional fields (e.g., conjugation class, frequency, annotation) may be added in the future as needed.
