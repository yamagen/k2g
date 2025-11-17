## **Notes on Glossing Principles**

Last change: 2025/10/21-15:35:59.

Hilofumi Yamamoto, Ph.D.

### Basic idea

The glossing system is written in two layers. One layer shows the flow of
meaning in a phrase or sentence. The other layer shows how each word works in
form and function. Keeping them apart makes the relation between meaning and
form easier to see.

### Structure

Gloss information is divided into two levels.

| Level            | Element                  | Focus                                  | Verb form                                  |
| ---------------- | ------------------------ | -------------------------------------- | ------------------------------------------ |
| **Phrase gloss** | `"phrase"` and `"gloss"` | the meaning flow of the sentence       | verb forms are not written                 |
| **Word gloss**   | `"words"` array          | grammatical and morphological function | verb forms are written (.ADV, .ATTR, etc.) |

### Example

#### Phrase gloss

```json
{
  "phrase": "夜更けぬとにやありけむ、やがていにけり。",
  "gloss": "night be.late PERF QUOT COP Q exist PST, immediately leave PST"
}
```

#### Word gloss

```json
{
  "words": [
    { "word": "夜", "gloss": "night" },
    { "word": "更け", "gloss": "be.late.ADV" },
    { "word": "ぬ", "gloss": "PERF" },
    { "word": "と", "gloss": "QUOT" },
    { "word": "に", "gloss": "COP.CONJ" },
    { "word": "や", "gloss": "Q" },
    { "word": "あり", "gloss": "EXIST" },
    { "word": "けむ", "gloss": "PST.SUPP" },
    { "word": "やがて", "gloss": "immediately" },
    { "word": "いに", "gloss": "go.ADV" },
    { "word": "けり", "gloss": "PST" }
  ]
}
```

### Notation rules

1. **Verb forms**
   - continuative form (連用形): `.ADV`
   - attributive form (連体形): `.ATTR`
   - realis form (已然形): `.REAL`
   - plain form (終止形): no mark

2. **Particles**
   - conjunctive particle like て: `CONJ`
   - case particles: を = `ACC`, に = `DAT`, が = `NOM`
   - focus or question particles: や・か = `Q` or `FOC`

3. **Auxiliary verbs**
   - ぬ (perfective): `PERF`
   - けり (past or exclamatory): `PST`
   - けむ (past conjecture): `PST.SUPP`
   - む (supposition): `SUPP`
   - なり (copula): `COP`
   - たり (result or continuation): `RES` or `CONT`

4. **Existence and copula**
   - あり: `EXIST`
   - なり (copula): `COP`
   - に (連用形 of なり): `COP.CONJ`

### Background

This structure follows the Leipzig Glossing Rules. The phrase gloss corresponds
to the translation tier, and the word gloss corresponds to the morphological
tier. This style extends the original rules to fit classical Japanese, where
auxiliary verbs and inflectional endings play a central role.

### Advantages

- **Clearer alignment** By keeping phrase and word glosses separate, it becomes
  easier to match meaning and form.

- **Independent layers** Each layer can be used on its own for syntax,
  semantics, or translation study.

- **Readability** The gloss stays compact, and the same format can be used
  across AEAD, _Tosa Nikki_, and _Ise Monogatari_ projects.

### Note

This plan reflects the standard used in October 2025. It can also serve as a
basis for linking gloss data with automatic parsers such as `k2g`.
