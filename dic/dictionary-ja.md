# 辞書ファイル仕様（dictionary-ja.md）

## 概要

このドキュメントでは、`k2g` プロジェクトにおける辞書ファイル `dictionary.json` のフォーマットおよび各項目の役割について説明する。

---

## ファイル形式

- フォーマット：JSON
- 構造：エントリの配列（Array of entries）
- 文字コード：UTF-8

---

## サンプルテンプレート

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

## 各項目の説明

| キー       | 説明                                           |
| ---------- | ---------------------------------------------- |
| `surface`  | 出現形（テキストに現れる語形）                 |
| `base`     | 基本形または原形（辞書に載る語形）             |
| `gloss`    | 対応する意味、または gloss 略号（例：PST.REP） |
| `features` | 品詞や文法機能を表すラベル（複数指定可）       |

---

## 備考

- 1エントリ＝1語形。複合語の場合はなるべく分割して登録すること。
- `features` のラベル体系は `features.json` にて別途定義予定。
- 辞書ファイルは UTF-8 で保存すること。
- 今後、必要に応じて拡張項目（例：活用型、頻度、注釈など）を追加する可能性がある。
