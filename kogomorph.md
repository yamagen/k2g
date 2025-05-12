# 古語形態素解析システム構築企画

## 概要

本プロジェクトは、『伊勢物語』『土佐日記』および AEAD（An Expression A Day）で蓄積された phrase gloss データを活用して、文脈に応じた高精度な古語の形態素解析システムを構築することを目的としています。従来の形態素解析システム（MeCab, Juman など）では対応が難しい、助動詞の意味分化や補助動詞構造、語用的含意を反映する分析を可能にします。

## 背景と強み

- 既に蓄積されたデータには、

  - 精密な逐語訳（translation-ja, translation-en）
  - Leipzig Glossing Rules に準拠した phrase-gloss
  - glossary-abbreviations による略号体系
  - phrase 単位での語順保存と文脈記述

- 「けり」「なり」「いますがり」などの複雑な助動詞や補助構造が明示的に分離・分類されている
- gloss と語義、文法的機能（格・相・敬語など）を分けて記録している

## 目的

- 形態素の分割と品詞ラベリング（POS tagging）
- gloss による文法機能の付与（例：PST.REP, ACC, HON）
- 文脈に応じた語義 disambiguation
- 補助動詞や助動詞構造の自動分離と解釈

## 機能構想

- phrase-gloss JSON からの辞書自動生成
- gloss → 品詞／機能変換ルールの定義
- 古典語テキストの入力 → 解析 → JSON 出力（形態素 + gloss + 品詞）

## 技術基盤

- Python による解析エンジン
- データ形式：JSON / Markdown / TSV
- 将来的には MeCab / Sudachi / spaCy との連携も視野に入れる

## 今後のステップ

1. gloss に使われている略号（abbreviations）の統一と整理
2. phrase-gloss の語分割ルールと品詞分類の形式化
3. サンプル解析スクリプトの設計
4. 小規模なテキスト（例：伊勢物語第1段）での解析実験

---

# README.md

## KogoGloss: Classical Japanese Morphological Analyzer

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
