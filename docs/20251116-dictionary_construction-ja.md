# k2g：連接実績辞書・単語辞書・gloss・活用形・出力形式に関する整理メモ

Last change: 2025/11/17-09:34:26.

Hilofumi Yamamoto, Ph.D.

# 1. k2g の基本理念：二種の辞書

k2g では辞書は **二種類** に明確に分離される。

## 1.1 連接実績辞書（morphotactics）

- 文献に実際に出現した語形（surface）を記録する辞書。
- 1 surface = 1 decomposition（内部構造）。
- 最長一致解析に使う。
- 形式は **jsonl**（1行1エントリ）が最適。

例：

```json
{ "surface": "しれず", "decomposition": ["ラ下二-未:知る", "消-用終:ず"] }
```

## 1.2 単語辞書（lexicon）

- lemma（見出し語）
- 品詞 pos, 活用型 class
- 活用形 forms
- 意味 gloss（語義）
- 文法機能 gloss（助動詞など）

例：

```json
{
  "lemma": "知る",
  "pos": "verb",
  "class": "ラ下二",
  "forms": {
    "mizen": "しれ",
    "renyou": "しれ",
    "shushi": "しる",
    "renta": "しる",
    "izen": "しれ",
    "meirei": "しれ"
  },
  "gloss": "know"
}
```

---

# 2. gloss の体系：三層構造

k2g における gloss は、次の 3 種類を区別する。

## 2.1 語義 gloss（semantic gloss）

- lemma の意味。
- **英語語彙で記述**（LGR の対象外）。
- 例：know, love, die, see…

## 2.2 文法 gloss（LGR 準拠）

- 助動詞・助詞の機能。
- NEG, VOL, RET, PFV, DUR など。
- 国際標準（Leipzig Glossing Rules）にできる限り準拠。

## 2.3 日本語古典語固有の形態 gloss（non-LGR）

- 未然形／連用形／終止形などの活用形に対応。
- LGR 非対象なので **IRR / ADV / FIN / ATTR / REALIS / IMP** を k2g 内部標準とする。

---

# 3. 活用形の内部表現と出力変換

内部コードは不変：

```
mizen / renyo / shushi / renta / izen / meirei
```

これを出力時に変換する：

| 内部キー | 日本語 | 英語        | gloss  |
| -------- | ------ | ----------- | ------ |
| mizen    | 未然   | irrealis    | IRR    |
| renyo    | 連用   | adverbial   | ADV    |
| shushi   | 終止   | finite      | FIN    |
| renta    | 連体   | attributive | ATTR   |
| izen     | 已然   | realis      | REALIS |
| meirei   | 命令   | imperative  | IMP    |

オプション例：

```
--form ja
--form en
--form gloss
--form none
```

---

# 4. 解析アルゴリズムの流れ

1. **morphotactics.jsonl で最長一致検索**
   例：「来なかった」→ surface ヒット

2. **decomposition を取得**

   ```
   ["カ変-未:来", "否定-連:なかっ", "過去-終:た"]
   ```

3. 各成分を解析（活用型・活用形・lemma 抽出）

4. lemma を **lexicon.json** へ問い合わせる

5. gloss（意味・文法機能）を lexicon 側から取得
   ※ morphotactics 側には gloss を持たせない（冗長・不整合防止のため）

6. 出力 renderer に渡す
   （plain / latex / md / html / none）

---

# 5. ユーザーの用途に応じた出力モード

## 5.1 分割のみ（split）

```
来 / なかっ / た
```

## 5.2 lemma だけ（lemma）

```
来      来る
なかっ  ず
た      た
```

## 5.3 完全解析（full）

```
来      来る    come    mizen
なかっ  ず      NEG     renyo
た      た      PST     shushi
```

---

# 6. 出力形式の切り替え

## 6.1 LaTeX（leipzig.sty）

```
\gll 来 なかっ た \\
    come NEG PST \\
\glend
```

## 6.2 Markdown（表・IGT・コードブロック）

| surface | lemma | gloss | form   |
| ------- | ----- | ----- | ------ |
| 来      | 来る  | come  | mizen  |
| なかっ  | ず    | NEG   | renyo  |
| た      | た    | PST   | shushi |

## 6.3 HTML（表・CSS で IGT スタイル可能）

```html
<table>
  <tr>
    <td>来</td>
    <td>来る</td>
    <td>come</td>
    <td>mizen</td>
  </tr>
  <tr>
    <td>なかっ</td>
    <td>ず</td>
    <td>NEG</td>
    <td>renyo</td>
  </tr>
  <tr>
    <td>た</td>
    <td>た</td>
    <td>PST</td>
    <td>shushi</td>
  </tr>
</table>
```

---

# 7. morphotactics.jsonl の最終形式

```
{"surface":"しれず","decomposition":["ラ下二-未:知る","消-用終:ず"]}
{"surface":"来なかった","decomposition":["カ変-未:来","否定-連:なかっ","過去-終:た"]}
{"surface":"思ひて","decomposition":["ハ四-連:思ふ","接続-て:て"]}
```

- gloss は入れない（単語辞書で管理するため冗長になる）
- jsonl は最長一致に最適

---

# 8. 本スレッドで確定したポイント（最重要）

- morphotactics（連接実績辞書）は **decomposition だけを持つ**
- gloss は **lexicon にのみ保存する**
- 活用形の内部コードは固定（mizen など）
- 表示はテーブル変換で日本語・英語・gloss を切替可能
- 出力は LaTeX / Markdown / HTML を renderer 層で処理
- jsonl 形式が最長一致辞書に最適
- “分割だけ” の軽量モードを提供すべき

---

# 9. 今後追加できる項目（必要なら作成可能）

- 完全版 lexicon.json スキーマ
- morphotactics.jsonl スキーマ
- renderer モジュール設計
- C 実装テンプレート（fgets + strstr + JSON parse）
- PHP 実装テンプレート（jsonl 逐次読み込み）
- CLI 仕様案（--mode, --form, --format）
