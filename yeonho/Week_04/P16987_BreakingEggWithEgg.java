package yeonho.Week_04;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P16987_BreakingEggWithEgg {
    static int N;
    static boolean[] isBroken;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        Egg[] eggs = new Egg[N];
        isBroken = new boolean[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            eggs[i] = new Egg(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        System.out.println(breakEgg(eggs, 0));
    }

    public static int breakEgg(Egg[] eggs, int idx) {
        if (idx == N) { // 모든 계란을 다 시도해본 경우
            return countBrokenEggs(eggs);
        }

        if (eggs[idx].getDurability() <= 0) { // 현재 계란이 이미 깨져있으면 다음으로 넘어감
            return breakEgg(eggs, idx + 1);
        }

        int max = 0;
        boolean allBroken = true;

        for (int i = 0; i < N; i++) {
            if (i == idx || eggs[i].getDurability() <= 0)
                continue; // 자기 자신이나 깨진 계란은 스킵

            allBroken = false; // 아직 부딪힐 계란이 있음

            // 계란 부딪히기
            eggs[idx].setDurability(eggs[idx].getDurability() - eggs[i].getWeight());
            eggs[i].setDurability(eggs[i].getDurability() - eggs[idx].getWeight());

            // 다음 계란으로 이동
            max = Math.max(max, breakEgg(eggs, idx + 1));

            // 상태 복구 (백트래킹)
            eggs[idx].setDurability(eggs[idx].getDurability() + eggs[i].getWeight());
            eggs[i].setDurability(eggs[i].getDurability() + eggs[idx].getWeight());
        }

        if (allBroken) { // 부딪힐 수 있는 계란이 없을 경우 다음 계란으로 넘어감
            return breakEgg(eggs, idx + 1);
        }

        return max;
    }

    // 깨진 계란의 개수를 세는 함수
    public static int countBrokenEggs(Egg[] eggs) {
        int count = 0;
        for (Egg egg : eggs) {
            if (egg.getDurability() <= 0)
                count++;
        }
        return count;
    }
}

class Egg {
    int durability;
    int weight;

    public Egg(int durability, int weight) {
        this.durability = durability;
        this.weight = weight;
    }

    public int getDurability() {
        return durability;
    }

    public void setDurability(int durability) {
        this.durability = durability;
    }

    public int getWeight() {
        return weight;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Egg{");
        sb.append("durability=").append(durability);
        sb.append(", weight=").append(weight);
        sb.append('}');
        return sb.toString();
    }
}
