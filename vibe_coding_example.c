#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 🎵 바이브 코딩 (Vibe Coding) - 고등학생용 예제
 * 음악 리듬에 맞춰 코딩하는 방법을 배워봅시다!
 * 
 * "바이브 코딩"은 음악의 비트와 리듬에 맞춰
 * 코드를 작성하고 실행하는 창의적인 프로그래밍 방식입니다.
 */

// 🎶 비트(Beat) 구조체 정의
typedef struct {
    int beat_number;      // 비트 번호 (1, 2, 3, 4...)
    char* note;           // 음표 (도, 레, 미...)
    int duration;         // 지속 시간 (밀리초)
    int intensity;        // 강도 (1~10)
} Beat;

// 🎼 곡(Song) 구조체 정의
typedef struct {
    char* title;
    int tempo;            // 분당 박자 (BPM)
    Beat* beats;
    int beat_count;
} Song;

// 🎵 비트를 출력하는 함수
void print_beat(Beat b) {
    printf("🎵 비트 #%d: [%s] ", b.beat_number, b.note);
    
    // 강도에 따라 다른 이모지 출력
    for (int i = 0; i < b.intensity; i++) {
        printf("●");
    }
    printf(" (지속: %dms)\n", b.duration);
}

// 🎼 곡 전체를 출력하는 함수
void print_song(Song s) {
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║        🎵 %s (BPM: %d) 🎵\n", s.title, s.tempo);
    printf("╚════════════════════════════════════════╝\n\n");
    
    for (int i = 0; i < s.beat_count; i++) {
        print_beat(s.beats[i]);
    }
}

// 📊 비트의 평균 강도를 계산하는 함수
double calculate_average_intensity(Song s) {
    int sum = 0;
    for (int i = 0; i < s.beat_count; i++) {
        sum += s.beats[i].intensity;
    }
    return (double)sum / s.beat_count;
}

// 🎯 특정 음표의 개수를 세는 함수
int count_note(Song s, char* target_note) {
    int count = 0;
    for (int i = 0; i < s.beat_count; i++) {
        if (strcmp(s.beats[i].note, target_note) == 0) {
            count++;
        }
    }
    return count;
}

// 🔄 비트 순서를 뒤집는 함수 (리믹스!)
void remix_song(Song s) {
    printf("\n🔄 리믹스 버전 (비트 역순):\n");
    printf("╔════════════════════════════════════════╗\n");
    
    for (int i = s.beat_count - 1; i >= 0; i--) {
        print_beat(s.beats[i]);
    }
    
    printf("╚════════════════════════════════════════╝\n");
}

// 💾 곡을 파일에 저장하는 함수
void save_song_to_file(Song s, char* filename) {
    FILE* file = fopen(filename, "w");
    
    if (file == NULL) {
        printf("❌ 파일 생성 실패!\n");
        return;
    }
    
    fprintf(file, "[%s]\n", s.title);
    fprintf(file, "BPM: %d\n", s.tempo);
    fprintf(file, "Beats: %d\n\n", s.beat_count);
    
    for (int i = 0; i < s.beat_count; i++) {
        fprintf(file, "%d,%s,%d,%d\n", 
                s.beats[i].beat_number,
                s.beats[i].note,
                s.beats[i].duration,
                s.beats[i].intensity);
    }
    
    fclose(file);
    printf("✅ 곡이 '%s' 파일에 저장되었습니다!\n", filename);
}

// 🎹 예제 1: 간단한 곡 만들기
void example_simple_song() {
    printf("\n════════════════════════════════════════\n");
    printf("📚 예제 1: 간단한 곡 만들기\n");
    printf("════════════════════════════════════════\n");
    
    Beat beats1[] = {
        {1, "도", 100, 8},
        {2, "레", 100, 6},
        {3, "미", 100, 7},
        {4, "도", 100, 9}
    };
    
    Song song1 = {
        .title = "반짝반짝 작은별",
        .tempo = 120,
        .beats = beats1,
        .beat_count = 4
    };
    
    print_song(song1);
}

// 🎵 예제 2: 곡 분석하기
void example_analyze_song() {
    printf("\n════════════════════════════════════════\n");
    printf("📚 예제 2: 곡 분석하기\n");
    printf("════════════════════════════════════════\n");
    
    Beat beats2[] = {
        {1, "도", 200, 5},
        {2, "도", 200, 6},
        {3, "미", 200, 7},
        {4, "미", 200, 8},
        {5, "도", 200, 5}
    };
    
    Song song2 = {
        .title = "학교종이 땡땡땡",
        .tempo = 100,
        .beats = beats2,
        .beat_count = 5
    };
    
    print_song(song2);
    
    // 분석
    printf("📊 곡 분석 결과:\n");
    printf("   - 평균 강도: %.2f\n", calculate_average_intensity(song2));
    printf("   - '도' 음표 개수: %d개\n", count_note(song2, "도"));
    printf("   - '미' 음표 개수: %d개\n", count_note(song2, "미"));
}

// 🎧 예제 3: 리믹스 만들기
void example_remix() {
    printf("\n════════════════════════════════════════\n");
    printf("📚 예제 3: 리믹스 만들기\n");
    printf("════════════════════════════════════════\n");
    
    Beat beats3[] = {
        {1, "파", 150, 7},
        {2, "솔", 150, 8},
        {3, "라", 150, 6}
    };
    
    Song song3 = {
        .title = "신나는 리듬",
        .tempo = 140,
        .beats = beats3,
        .beat_count = 3
    };
    
    print_song(song3);
    remix_song(song3);
}

// 💾 예제 4: 곡 저장하기
void example_save_song() {
    printf("\n════════════════════════════════════════\n");
    printf("📚 예제 4: 곡을 파일에 저장하기\n");
    printf("════════════════════════════════════════\n");
    
    Beat beats4[] = {
        {1, "도", 100, 5},
        {2, "레", 100, 6},
        {3, "미", 100, 7}
    };
    
    Song song4 = {
        .title = "내 첫 곡",
        .tempo = 110,
        .beats = beats4,
        .beat_count = 3
    };
    
    save_song_to_file(song4, "my_vibe_song.txt");
}

// 🎯 도전 과제
void challenge_exercise() {
    printf("\n════════════════════════════════════════\n");
    printf("⭐ 도전 과제\n");
    printf("════════════════════════════════════════\n");
    printf("다음을 직접 코딩해보세요!\n\n");
    printf("1️⃣ 5개 이상의 비트로 새로운 곡을 만들기\n");
    printf("2️⃣ 가장 강도가 높은 비트를 찾는 함수 만들기\n");
    printf("3️⃣ 총 재생 시간을 계산하는 함수 만들기\n");
    printf("4️⃣ 비트를 추가/삭제하는 함수 만들기\n\n");
}

// 🎬 메인 함수
int main() {
    printf("\n🎵🎵🎵 바이브 코딩 (Vibe Coding) 예제 🎵🎵🎵\n");
    printf("C언어로 배우는 창의적인 프로그래밍!\n\n");
    
    // 모든 예제 실행
    example_simple_song();
    example_analyze_song();
    example_remix();
    example_save_song();
    challenge_exercise();
    
    printf("\n════════════════════════════════════════\n");
    printf("✨ 프로그래밍의 새로운 감각을 느껴보세요! ✨\n");
    printf("════════════════════════════════════════\n\n");
    
    return 0;
}
