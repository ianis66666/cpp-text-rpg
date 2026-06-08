# Dungeon Quest Text RPG

這是一個 C++ 文字版 RPG 小遊戲作業。遊戲採用 CLI 文字介面與回合制戰鬥，玩家需要一路擊敗三個怪物，取回失落水晶。

GitHub repo: <https://github.com/ianis66666/cpp-text-rpg>

## 作業需求對照

本專案符合題目要求：

- 使用 C++ 製作 CLI 文字遊戲
- 至少包含四個 class：`Player`、`Skill`、`Item`、`Monster`
- 具備基本戰鬥流程與互動選單
- 使用 private 成員變數、public function、getter、setter，符合基本 OOP 設計
- 額外加入多關卡、多技能、多物品、金幣獎勵、隨機事件等創意功能

## 檔案架構

```text
cpp-text-rpg/
├─ main.cpp
├─ Player.h
├─ Player.cpp
├─ Skill.h
├─ Skill.cpp
├─ Item.h
├─ Item.cpp
├─ Monster.h
├─ Monster.cpp
├─ build.bat
├─ docs/
│  └─ USER_MANUAL.md
├─ README.md
└─ .gitignore
```

## 編譯方式

Windows PowerShell 或 CMD：

```bat
build.bat
```

或手動使用 g++：

```bat
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Player.cpp Skill.cpp Item.cpp Monster.cpp -o dungeon_quest.exe
```

執行：

```bat
dungeon_quest.exe
```

## 遊戲操作

玩家每回合可以選擇：

```text
1. Normal Attack
2. Use Skill
3. Use Item
4. Show Status
```

操作說明：

- `Normal Attack`：使用普通攻擊。
- `Use Skill`：選擇技能攻擊，需要消耗 MP。
- `Use Item`：使用補血藥水或回魔藥水。
- `Show Status`：查看玩家與怪物目前狀態。

## Class 設計

### Player

負責玩家角色資料與玩家行為。

主要變數：

- `name`：角色名稱
- `hp` / `maxHp`：目前血量與最大血量
- `mp` / `maxMp`：目前魔力與最大魔力
- `attackPower`：攻擊力
- `gold`：金幣
- `items`：持有物品
- `skills`：持有技能

主要 function：

- `attack()`：普通攻擊怪物
- `takeDamage()`：受到傷害
- `useItem()`：使用物品
- `useSkill()`：使用技能
- `isAlive()`：判斷玩家是否存活

### Skill

負責技能資料與技能資訊顯示。

主要變數：

- `name`：技能名稱
- `damage`：技能傷害
- `mpCost`：魔力消耗

主要 function：

- `use()`：使用技能並回傳傷害
- `showInfo()`：顯示技能資訊
- `getDamage()`：取得技能傷害

### Item

負責物品資料與使用效果。

主要變數：

- `name`：物品名稱
- `type`：物品類型，例如 `heal` 或 `mp`
- `effectValue`：效果數值
- `quantity`：數量

主要 function：

- `use()`：使用物品
- `showInfo()`：顯示物品資訊
- `isAvailable()`：判斷物品是否可使用

### Monster

負責怪物資料與怪物行為。

主要變數：

- `name`：怪物名稱
- `hp` / `maxHp`：目前血量與最大血量
- `attackPower`：攻擊力
- `rewardGold`：擊敗後獲得金幣

主要 function：

- `attack()`：攻擊玩家
- `takeDamage()`：受到傷害
- `isAlive()`：判斷怪物是否存活
- `showInfo()`：顯示怪物資訊

## 勝利與失敗條件

- 勝利：玩家擊敗三個怪物，取回失落水晶。
- 失敗：玩家 HP 歸零。

## 創意功能

- 三個連續關卡
- 兩種技能：`Fire Slash`、`Thunder Strike`
- 兩種物品：補血藥水、回魔藥水
- 擊敗怪物可獲得金幣
- 關卡開始前可能發生隨機事件，例如回血、回魔或陷阱
- 每關結束後玩家會短暫休息，恢復部分 HP 和 MP

## 小組分工建議

| 組員 | 負責內容 |
| --- | --- |
| 組員 1 | `Player.h`、`Player.cpp`、玩家狀態與攻擊功能 |
| 組員 2 | `Skill.h`、`Skill.cpp`、技能資料與技能使用 |
| 組員 3 | `Item.h`、`Item.cpp`、`Monster.h`、`Monster.cpp` |
| 組員 4 | `main.cpp`、遊戲流程整合、README、Word 文件與截圖 |
