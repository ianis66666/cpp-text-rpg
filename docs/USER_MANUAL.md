# Dungeon Quest Text RPG 使用說明文件

## 一、遊戲名稱與小組成員

遊戲名稱：Dungeon Quest Text RPG

小組成員：

| 成員 | 負責內容 |
| --- | --- |
| 組員 1 | Player class、角色資料、玩家攻擊與受傷判斷 |
| 組員 2 | Skill class、技能資料、技能使用與 MP 消耗 |
| 組員 3 | Item class、Monster class、物品與怪物功能 |
| 組員 4 | main.cpp、戰鬥流程整合、GitHub、Word 文件與截圖 |

## 二、GitHub 專案連結

https://github.com/ianis66666/cpp-text-rpg

## 三、遊戲背景

玩家扮演一名進入地下城的勇者，目標是擊敗地下城中的怪物並取回失落水晶。遊戲採用文字介面，玩家透過輸入數字進行操作。

## 四、遊戲操作方式

遊戲開始後，玩家先輸入角色名稱。進入戰鬥後，每回合可以選擇以下行動：

```text
1. Normal Attack
2. Use Skill
3. Use Item
4. Show Status
```

操作說明：

- 輸入 `1`：普通攻擊怪物。
- 輸入 `2`：開啟技能選單，選擇技能攻擊。
- 輸入 `3`：開啟物品選單，使用補血藥水或回魔藥水。
- 輸入 `4`：查看玩家和怪物目前狀態。

## 五、角色、技能、物品、怪物介紹

### Player 角色

玩家角色具有名稱、HP、MP、攻擊力、金幣、物品與技能。玩家可以攻擊、使用技能、使用物品，也會受到怪物攻擊。

### Skill 技能

本遊戲設計兩種技能：

| 技能名稱 | 傷害 | MP 消耗 |
| --- | ---: | ---: |
| Fire Slash | 32 | 12 |
| Thunder Strike | 45 | 20 |

### Item 物品

本遊戲設計兩種物品：

| 物品名稱 | 類型 | 效果 | 數量 |
| --- | --- | ---: | ---: |
| Small Potion | 補血 | 恢復 30 HP | 3 |
| Mana Potion | 回魔 | 恢復 20 MP | 2 |

### Monster 怪物

本遊戲共有三個關卡怪物：

| 怪物名稱 | HP | 攻擊力 | 獎勵金幣 |
| --- | ---: | ---: | ---: |
| Slime | 55 | 8 | 15 |
| Goblin | 80 | 12 | 25 |
| Dark Knight | 120 | 18 | 50 |

## 六、Class 設計說明

### Player class

主要變數：

- `name`：角色名稱
- `hp`：角色血量
- `attackPower`：攻擊力
- `items`：擁有的物品
- 額外加入 `mp`、`gold`、`skills`

主要 function：

- `attack()`：攻擊怪物
- `takeDamage()`：受到傷害
- `useItem()`：使用物品
- `isAlive()`：判斷角色是否存活
- 額外加入 `useSkill()`、`heal()`、`restoreMp()`、`showStatus()`

### Skill class

主要變數：

- `name`：技能名稱
- `damage`：技能傷害
- `mpCost`：魔力消耗

主要 function：

- `use()`：使用技能
- `showInfo()`：顯示技能資訊
- `getDamage()`：取得技能傷害

### Item class

主要變數：

- `name`：物品名稱
- `type`：物品類型
- `effectValue`：效果數值
- `quantity`：數量

主要 function：

- `use()`：使用物品
- `showInfo()`：顯示物品資訊
- `isAvailable()`：判斷物品是否可使用

### Monster class

主要變數：

- `name`：怪物名稱
- `hp`：怪物血量
- `attackPower`：攻擊力
- `rewardGold`：擊敗後獲得金幣

主要 function：

- `attack()`：攻擊玩家
- `takeDamage()`：受到傷害
- `isAlive()`：判斷怪物是否存活
- `showInfo()`：顯示怪物資訊

## 七、勝利與失敗條件

勝利條件：玩家擊敗三個怪物，成功取回失落水晶。

失敗條件：玩家 HP 歸零。

## 八、額外創意功能

- 多關卡設計，共三個怪物。
- 多技能設計，不同技能有不同傷害與 MP 消耗。
- 多物品設計，可以補 HP 或補 MP。
- 擊敗怪物後可以獲得金幣。
- 關卡開始前有隨機事件，可能回血、回魔或受到陷阱傷害。
- 每關結束後會短暫休息，恢復部分 HP 與 MP。

## 九、遊戲畫面或執行結果截圖

請在 Word 文件中插入以下畫面截圖：

1. 編譯成功畫面。
2. 遊戲開始畫面。
3. 戰鬥選單畫面。
4. 使用技能或物品畫面。
5. 勝利或失敗結算畫面。
