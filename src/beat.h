#ifndef BEAT_H
#define BEAT_H

/*
 * 🎵 비트(Beat) 헤더 파일
 * Beat 구조체와 관련 함수들을 선언합니다.
 */

// 🎶 비트(Beat) 구조체 정의
typedef struct {
    int beat_number;      // 비트 번호 (1, 2, 3, 4...)
    char* note;           // 음표 (도, 레, 미...)
    int duration;         // 지속 시간 (밀리초)
    int intensity;        // 강도 (1~10)
} Beat;

/* 함수 선언 */

/**
 * 새로운 Beat를 생성합니다.
 */
Beat create_beat(int beat_number, const char* note, int duration, int intensity);

/**
 * Beat를 출력합니다.
 */
void print_beat(Beat b);

/**
 * Beat를 해제합니다.
 */
void free_beat(Beat* b);

/**
 * 두 Beat가 같은지 비교합니다.
 */
int beats_equal(Beat b1, Beat b2);

#endif
