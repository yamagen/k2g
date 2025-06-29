# K2G + FPS-ID + CW + Visualization: 古典語テキスト解析の統合パイプライン

## 【概要】

本ドキュメントは、以下の4つのコンポーネントで構成される古典語テキスト解析パイプラインの全体像を整理したものである：

1. **K2G**（Koten to Gloss）：古語形態素解析システム
2. **FPS-ID**（Frequency-based PCA Semantic ID）：意味識別子の自動生成
3. **CW**（Cooccurrence Weighting）：共起構造の重みづけ分析
4. **Visualization**：意味クラスタの視覚化

これらは、既存の gloss データ（AEAD, 伊勢物語, 土佐日記）を活用し、辞書設計や大規模ベクトル訓練なしで、古語の語義・構文・語り構造を柔軟かつ解釈可能に分析することを目指す。

---

## 【全体フロー図（Mermaid簡易版）】

```mermaid
flowchart TD
    A[Classical Texts (Ise, Tosa)] --> B[K2G: Morphological Analysis]
    B --> C[FPS-ID: PCA-Based Semantic ID]
    C --> D[CW: Cooccurrence Weighting]
    D --> E[Visualization: Graph View]
```

---

## 【コンポーネント概要】

### 1. K2G: 古語形態素解析 (k2g)

- gloss データに基づく分割 + 品詞ラベルの付与
- Leipzig Glossing Rules に準拠した記述構造
- 接続規則は使用せず、最大一致と明示辞書エントリにより解析
- 実装言語は **すべて C 言語** とし、外部依存を最小限に抑える

### 2. FPS-ID: Frequency-based PCA Semantic ID

- 文脈単位で語の共起をカウントし、共起ベクトルを生成
- PCA により 1〜2次元に圧縮し、小数点付きの意味IDとして表示（例：23.6147）
- 桁数に応じて意味解像度を制御（上位桁＝大分類、下位桁＝文脈差）
- PCA処理も含め、すべて C 言語により実装（必要に応じて LAPACK 等のCライブラリを使用）

### 3. CW: Cooccurrence Weighting

- `streamtext.jsonl` 形式から `fps-id` に基づいて語をグループ化し、共起重みを算出
- `-k fps-id -digit 6` のように桁数でグルーピング精度を調整
- 重み式：`cw(t1, t2) = ctf × √(idf1 × idf2)` を C 言語で実装
- JSONL の処理も C によるストリーム構文で処理し、makeによるビルド制御

### 4. Visualization

- CWの出力（fps-id1 fps-id2 weight）を `.dot` 形式に変換し、GraphvizでSVG等へ可視化
- 意味的な近接構造を視覚的に捉えることで、和歌的連想、語群の自動分類、創造的発見が可能になる
- C 言語で `.dot` ファイルの生成を行い、外部描画には `dot` コマンドを用いる

---

## 【今後の開発方向性】

| フェーズ          | 抽出する機能 / ツール                                         |
| ----------------- | ------------------------------------------------------------- |
| `k2g-dictgen`     | phrase-gloss から辞書ファイル（TSVまたはJSON）を生成（C実装） |
| `k2g-analyze`     | 古典語テキストの逐語形態素解析エンジン（C実装）               |
| `fpsid-gen`       | 共起行列計算・PCA変換・fps-id付与（C実装）                    |
| `cw`              | ID桁数による共起重み集計、視覚化用出力含む（C実装）           |
| `fpsid2text.tsv`  | fps-id と語表の対応辞書（Cツールによる変換）                  |
| `cluster-browser` | GUIによる意味クラスタ探索（Web環境で別途開発）                |

---

## 【結論】

この "K2G + FPS-ID + CW + Visualization" パイプラインは、手動では解析が困難な古語、特に語り、語用論、言語創造的な意味の連接を含む表現に対して、

- 辞書 + gloss による明示的で柔軟な形態素解析
- 意味IDの数値による秩序化と階層性の獲得
- 共起関係のモデル化と視覚的分析支援

を達成する設計である。

全構成要素は C 言語で構築され、UNIXツールチェインと連携可能な軽量・高速な処理系を目指す。
Pythonやその他の高水準スクリプトには依存せず、堅牢性と制御性を備えた解析環境として構築される。
