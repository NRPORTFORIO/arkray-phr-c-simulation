# ==========================================
# 【エッジAI】外部ライブラリ（NumPy）を使わない
# 血糖値予測・線形回帰（最小二乗法）のスクラッチ実装
# ==========================================

# 過去のデータ（C言語の構造体から出力されたと想定するデータ）
# X: 1日の歩数（単位：千歩）
X = [3.0, 5.0, 8.0, 4.0, 6.0]
# y: 翌朝の血糖値（mg/dL）
y = [150, 135, 110, 142, 128]

# データの個数
N = len(X)

# 1. 各データの平均値を計算
mean_X = sum(X) / N
mean_y = sum(y) / N

# 2. 傾き（a）と切片（b）を求めるための数理計算（最小二乗法）
# 傾き a = 共分散 / Xの分散
covariance = 0.0
variance_X = 0.0

for i in range(N):
    diff_X = X[i] - mean_X
    diff_y = y[i] - mean_y
    covariance += diff_X * diff_y
    variance_X += diff_X ** 2

# AIモデルのパラメータ（傾き a と 切片 b）を確定
a = covariance / variance_X
b = mean_y - (a * mean_X)

print("--- AI学習プロセス完了 ---")
print(f"導き出した予測式: 血糖値 = {a:.2f} * 歩数 + {b:.2f}")
print("※歩数が増える（運動する）ほど、血糖値が下がる傾向をAIが数理的に学習しました。")
print("---------------------------\n")

# 3. 未来の予測：もし明日「7千歩」歩いた場合の血糖値をAIが予測
future_step = 7.0
predicted_glucose = (a * future_step) + b

print("--- AI予測結果 ---")
print(f"明日【 {future_step} 千歩 】歩いた場合の、AIによる予測血糖値は【 {predicted_glucose:.1f} mg/dL 】です。")
print("------------------")
