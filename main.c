#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// =================================================================
// 1. 構造体（struct）の定義
// アークレイの糖尿病患者向け健康管理（PHR）アプリをイメージし、
// 日々のバイタルデータを1つの型に集約して管理します。
// =================================================================
typedef struct {
    char date[11];      // 日付 (例: "2026-10-06")
    int blood_sugar;    // 血糖値 (mg/dL)
    int steps;          // 歩数 (歩)
    int blood_pressure; // 収縮期血圧 (最高血圧, mmHg)
    bool is_alert;      // 医療アラートフラグ (trueで警告)
} HealthRecord;

// =================================================================
// 2. 関数プロトタイプ宣言（すべて構造体ポインタ渡し）
// メモリ負荷を抑え、高速に処理を行うためにアドレス参照（ポインタ）を活用
// =================================================================
void init_record(HealthRecord *record, const char *date, int blood_sugar, int steps, int blood_pressure);
void check_medical_alert(HealthRecord *record);
void display_all_records(const HealthRecord *records, int count);
void calculate_summary(const HealthRecord *records, int count);

int main(void) {
    printf("--- アークレイPHRアプリ コアロジック・シミュレータ ---\n\n");

    // 3日分の健康データを格納する構造体配列を用意
    HealthRecord user_data[3];

    // ポインタ経由でサンプルデータを初期化・登録
    init_record(&user_data[0], "2026-10-04", 110, 8500,  125);
    init_record(&user_data[1], "2026-10-05", 155, 4200,  135); // 血糖値・血圧高め
    init_record(&user_data[2], "2026-10-06", 120, 11000, 118);

    // 登録された全データの表示
    display_all_records(user_data, 3);

    // 期間内の集計（平均血糖値・総歩数）の計算と表示
    calculate_summary(user_data, 3);

    return 0;
}

// =================================================================
// 関数の実装：構造体ポインタ（*record）を使ってデータを登録
// =================================================================
void init_record(HealthRecord *record, const char *date, int blood_sugar, int steps, int blood_pressure) {
    strcpy(record->date, date);
    record->blood_sugar = blood_sugar;
    record->steps = steps;
    record->blood_pressure = blood_pressure;
    record->is_alert = false; // 初期値はアラートなし

    // データ登録時に自動で医療アラートチェックを実行
    check_medical_alert(record);
}

// =================================================================
// 関数の実装：論理回路・条件分岐（if文）による自動アラート制御
// 血糖値140以上、または最高血圧130以上の場合にアラートフラグを制御
// =================================================================
void check_medical_alert(HealthRecord *record) {
    if (record->blood_sugar >= 140 || record->blood_pressure >= 130) {
        record->is_alert = true;
    }
}

// =================================================================
// 関数の実装：全レコード一覧表示（constポインタで読み取り専用にして安全性を確保）
// =================================================================
void display_all_records(const HealthRecord *records, int count) {
    printf("[ 日々のご利用データ一覧 ]\n");
    printf("-----------------------------------------------------------------\n");
    printf("日付       | 血糖値(mg/dL) | 歩数(歩) | 血圧(mmHg) | ステータス\n");
    printf("-----------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        // ポインタ（->）を使って各要素にアクセス
        printf("%s | %-13d | %-8d | %-8d | ", 
               records[i].date, records[i].blood_sugar, records[i].steps, records[i].blood_pressure);
        
        if (records[i].is_alert) {
            printf("⚠️要注意(高バイタル)\n");
        } else {
            printf("正常\n");
        }
    }
    printf("-----------------------------------------------------------------\n\n");
}

// =================================================================
// 関数の実装：平均血糖値と総歩数の計算（コスト・原価計算で培った集計ロジックの応用）
// =================================================================
void calculate_summary(const HealthRecord *records, int count) {
    int total_blood_sugar = 0;
    int total_steps = 0;

    for (int i = 0; i < count; i++) {
        total_blood_sugar += records[i].blood_sugar;
        total_steps += records[i].steps;
    }

    double average_blood_sugar = (double)total_blood_sugar / count;

    printf("[ 期間中のサマリー集計結果 ]\n");
    printf("・平均血糖値 : %.1f mg/dL\n", average_blood_sugar);
    printf("・総歩数     : %d 歩\n", total_steps);
    printf("---------------------------------------------\n");
}
