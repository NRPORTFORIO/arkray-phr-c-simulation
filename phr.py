# WandboxのPython環境で動く簡易AI（線形回帰のイメージ）
# 過去の「歩数」と「血糖値」の関係から、未来の血糖値を簡易予測するロジック

import numpy as np

# 過去のデータ（C言語の構造体から出力されたと想定するデータ）
# [歩数(千歩)]
X = np.array([2, 4, 6, 8, 10]) 
# [翌朝の血糖値]
y = np.array([160, 150, 135, 120, 115]) 

# 簡易的な最小二乗法（機械学習の原点である線形回帰の計算）による学習
# y = ax + b の傾き(a)と切片(b)を計算
a, b = np.polyfit(X, y, 1)

print(f"【AI学習完了】 予測式: 血糖値 = {a:.2f} * 歩数 + {b:.2f}")

# 未来の予測：もし明日「7千歩」歩いた場合の血糖値をAIが予測
future_step = 7
predicted_glucose = a * future_step + b
print(f"【AI予測結果】 明日 {future_step}千歩 歩いた場合の予測血糖値: {predicted_glucose:.1f} mg/dL")
