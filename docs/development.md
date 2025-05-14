# 古語形態素解析システム 開発メモ（development.md）

## プロジェクト概要

本プロジェクトは、古典日本語テキスト（例：『伊勢物語』『土佐日記』）の精密な形態素解析を行うための軽量かつ高速なC言語実装を目的とする。人間可読なJSON形式の辞書を元に、事前コンパイルされたバイナリ辞書を用いてリアルタイムな解析を行う構成を取る。

---

## ファイル構成

### 1. `k2g.c`（**Koten to Gloss Filter**）

- 形態素解析本体
- 入力テキストを解析し、辞書と照合して形態素・品詞・gloss を出力
- 使用辞書：`dictionary.kmf`（バイナリ辞書）

### 2. `prebtreecomp.c`（**Pre-B-Tree Compiler**）

- 辞書コンパイラ
- `dictionary.json` を読み込み、ソート・構造体変換・バイナリ化して `dictionary.kmf` を生成
- 照合用にソート済みのバイナリ検索配列などを構成

### 3. `dictionary.json` / `dictionary.dict`

- `dictionary.json`: 編集可能な辞書ソース。エントリは以下の形式：

```json
{
  "surface": "けり",
  "base": "けり",
  "gloss": "PST.REP",
  "features": ["aux", "past", "reportative"]
}
```

- `dictionary.dict`: `prebtreecomp.c` によって生成される高速検索用の辞書ファイル。`kmf.c` から直接読み込む。

---

## 特徴と方針

- 高速な解析を目指して、起動時の辞書読込はバイナリ形式に限定
- ユーザーは `dictionary.json` に自由に語を追加可能
- 未収録語が出現した場合は通知し、`dictionary.json` に追記して再コンパイルすれば解析精度が上がる
- 連接規則は当面導入せず、語の出現順と形態情報の照合のみで処理を行う方針とする

---

## 多言語対応（gloss解釈と出力のローカライズ）

- 出力中の `features` ラベルの意味づけには、`locales/features-XX.json`（XX = ja, en, frなど）を参照する。
- 実行時に `-l ja` / `-l en` などの引数で使用言語を切り替える（例：`k2g -l en`）。
- `features-XX.json` は構造体の分類とラベルを提供する人間可読JSONであり、バイナリ化は不要。
- ディレクトリ名は国際的に通用する `locales/` を採用：

```
locales/
├── features-ja.json
├── features-en.json
└── features-fr.json（将来的に）
```

---

## 検討中・今後の課題

- `DictEntry` 構造体の固定長設計 or 可変長対応
- UTF-8対応の文字列比較と分割（必要に応じて既存のksf処理を援用）
- feature の標準ラベル体系（例："PST", "HON", "ACC" など）と略語の揺れ統一
- 複合語・補助動詞処理の構文ルール整備
- compile_dict.c の処理フロー
- dictionary.json から .dict への中間構造（構造体）仕様
- features.json との照合・検証ルーチンの設計方針

---

## メモ・その他

- プロジェクト名：`k2g`（Koten to Gloss）
- 将来的には MeCab のユーザー辞書形式との互換性も視野に入れる
- `k2g.c` は UNIXフィルタとしても使用可能なように設計する（標準入力→標準出力）
