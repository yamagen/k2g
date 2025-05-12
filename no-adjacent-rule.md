# 連接規則を導入しない方針について（no-adjacent-rule.md）

## はじめに

本ドキュメントでは、古語形態素解析システムの設計において、**連接規則（adjacency rules）を導入しない**という方針を採用する理由と、その言語的・実装的意義について整理する。

---

## 連接規則とは

連接規則とは、品詞や文法カテゴリー間の接続可能性・接続コストを記述した表であり、形態素解析における語の分割や連結の妥当性を数値的に評価する仕組みである。たとえば：

| 前項品詞 | 後項品詞 | 接続可否 | コスト |
| -------- | -------- | -------- | ------ |
| 名詞     | 助詞     | 可       | 100    |
| 動詞     | 動詞     | 不可     | -      |

このような表をもとに、曖昧な語の分割を「文法的にもっとも自然な接続」として解決する手法は、MeCabなどの現代語解析器で標準的に使われている。

---

## 連接規則の導入による弊害

### 1. **新しい連接の発見が阻害される**

連接規則は「過去に存在した接続例のカタログ」であり、未知の連語や破格的な構文が原理的に排除されてしまう。言語使用の創造的・詩的変化や語りの逸脱が本質的な資料（例：和歌、伊勢物語）では、これは重大な損失である。

### 2. **構造の透明性が失われる**

連接規則によって解析が決定された場合、その決定がどの規則によるものかがブラックボックス化しやすく、言語学的検証や gloss の構造的整合性を妨げる。

### 3. **辞書との二重管理による保守性の低下**

品詞分類と連接規則をそれぞれ管理・更新する必要が生じ、特に語義や用法を細かく gloss で記述している本プロジェクトでは、大幅な作業負荷の増加を招く。

### 4. **未知語処理との非相性**

辞書に存在しない語が現れたとき、その語に品詞が割り当てられないため、連接規則を参照することができず、解析そのものが破綻するリスクが高まる。

---

## 採用方針：連接規則を導入しない

本プロジェクトでは、以下のような設計方針を採用する：

- 語の出現順と gloss に含まれる文法情報のみで解析を進める
- 曖昧な分割は「最大一致」方式と人手補完によって解決する
- 連接の創造性や破格表現の自由を守るため、**連接規則は導入しない**
- 必要が生じた場合に限り、明示的な語連接パターンを辞書レベルで記述する（例："いますがり" → います + がり）

---

## 結語

連接規則は、汎用的な解析器には有効な仕組みだが、創造的な語の使用、語りの逸脱、語用論的変化を扱うには不向きである。本プロジェクトでは、連接規則なしで得られる自由と柔軟性を最大限に活かし、語と語のつながりの観察と発見に主眼を置いた設計を採用する。

（この方針は必要に応じて将来再検討されることがある）

---

# On the Policy of Avoiding Adjacency Rules

## Introduction

This document outlines the rationale for deliberately avoiding **adjacency rules** in the design of the classical Japanese morphological analysis system, and explains the linguistic and implementation-level implications of that choice.

---

## What are Adjacency Rules?

Adjacency rules define the grammatical compatibility and connection cost between pairs of parts of speech. They are typically used in modern morphological analyzers (e.g., MeCab) to resolve segmentation ambiguities by preferring the most natural connections, based on a predefined matrix:

| Prev POS | Next POS | Connectable | Cost |
| -------- | -------- | ----------- | ---- |
| Noun     | Particle | Yes         | 100  |
| Verb     | Verb     | No          | -    |

---

## Drawbacks of Adjacency Rules

### 1. **Hinders the Discovery of New Connections**

Since adjacency rules are based on existing patterns, they inherently block novel or poetic constructions, which are vital in historical texts like _Ise Monogatari_ or waka poetry.

### 2. **Reduces Structural Transparency**

When analysis results are governed by opaque connection tables, it becomes difficult to trace the logic behind segmentations, obstructing linguistic scrutiny and consistent glossing.

### 3. **Increases Maintenance Burden**

Maintaining a separate rule table alongside a detailed feature-rich dictionary results in duplicated work, especially when precise semantic or grammatical glosses are prioritized.

### 4. **Incompatible with Unknown Words**

When a word is not found in the dictionary, it lacks a defined POS, making the adjacency rule system unusable and causing the analysis to fail.

---

## Adopted Policy: No Adjacency Rules

This project adopts the following design policy:

- Parsing is performed solely based on word order and glossed grammatical information.
- Ambiguities are resolved using the maximum-match strategy and manual intervention.
- To preserve flexibility and allow novel combinations, **no adjacency rule tables are used**.
- If needed, recurring compound patterns may be explicitly registered in the dictionary (e.g., "imasugari" = "imasu" + "gari").

---

## Conclusion

While adjacency rules are useful in generalized NLP systems, they are not suitable for projects focusing on creative usage, poetic deviation, or discourse-level nuance. By omitting such rules, this project prioritizes linguistic exploration and structural clarity.

(This policy may be reconsidered in the future if warranted.)
