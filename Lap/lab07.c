#include <iostream>  // สำหรับการรับ-ส่งข้อมูล (cin, cout)
#include <cstdlib>   // สำหรับการสุ่มตัวเลข (rand) และฟังก์ชันอื่นๆ
#include <ctime>     // สำหรับการใช้เวลาปัจจุบันในการสร้าง seed เพื่อให้การสุ่มไม่ซ้ำกัน
#include <limits>    // สำหรับจัดการกับค่าสูงสุดของ stream

int main() {
    int choice; // ตัวแปรสำหรับเก็บตัวเลือกของผู้เล่น (1=เล่น, -1=ออก)
    srand(time(NULL)); // ตั้งค่าเริ่มต้นให้กับการสุ่มตัวเลข เพื่อให้ได้เลขที่แตกต่างกันทุกครั้งที่รัน

    // วนลูปหลักของโปรแกรมเพื่อให้ผู้เล่นสามารถเลือกเล่นซ้ำได้
    while (true) {
        std::cout << "Do you want to play game (1=play,-1=exit) :\n";
        
        // รับค่าจากผู้ใช้
        std::cin >> choice;

        // ตรวจสอบว่าผู้ใช้ใส่ข้อมูลที่ไม่ใช่ตัวเลขหรือไม่ (เช่น ใส่ตัวอักษร)
        if (std::cin.fail()) {
            std::cout << "Invalid input. The program will exit.\n";
            break; // ออกจากลูปและจบโปรแกรม
        }

        // ถ้าผู้ใช้เลือก -1 ให้จบโปรแกรม
        if (choice == -1) {
            std::cout << "See you again.\n";
            break; // ออกจากลูปและจบโปรแกรม
        }

        // ถ้าผู้ใช้ใส่ตัวเลขอื่นที่ไม่ใช่ 1 หรือ -1 ให้วนกลับไปถามใหม่
        if (choice != 1) {
            continue; // ข้ามส่วนที่เหลือและกลับไปที่จุดเริ่มต้นของลูป
        }

        // --- เริ่มต้นเกม ---
        int score = 100; // ตั้งคะแนนเริ่มต้นที่ 100
        int winningNumber = rand() % 100 + 1; // สุ่มเลขที่ถูกต้องระหว่าง 1-100
        int guess; // ตัวแปรสำหรับเก็บตัวเลขที่ผู้เล่นทาย
        int lowerBound = 1; // ขอบเขตล่างของการทาย
        int upperBound = 100; // ขอบเขตบนของการทาย

        std::cout << "\n(Score=" << score << ")\n\n";

        // ลูปสำหรับการทายตัวเลข
        do {
            std::cout << "Guess the winning number (" << lowerBound << "-" << upperBound << ") :\n";
            std::cin >> guess;

            // ตรวจสอบว่าผู้เล่นใส่ข้อมูลที่ไม่ใช่ตัวเลขระหว่างการเล่นหรือไม่
            if (std::cin.fail()) {
                std::cout << "Invalid input. Exiting game.\n";
                std::cin.clear(); // ล้างสถานะข้อผิดพลาดของ stream
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ทิ้งข้อมูลส่วนเกินใน buffer
                break; // ออกจากลูปการเล่นเกม
            }

            // ถ้าทายถูก
            if (guess == winningNumber) {
                std::cout << "\nThat is correct! The winning number is " << winningNumber << ".\n";
                std::cout << "\nScore this game: " << score << "\n\n";
            } else {
                // ถ้าทายผิด ให้ลบคะแนน 10 หน่วย
                score -= 10;
                
                // ถ้าคะแนนเหลือ 0 หรือน้อยกว่า ให้จบเกม
                if (score <= 0) {
                    std::cout << "\nSorry, you ran out of score. The winning number was " << winningNumber << ".\n";
                    std::cout << "Score this game: 0\n\n";
                    break; // ออกจากลูปการเล่นเกม
                }
                
                // บอกใบ้ว่าเลขที่ถูก "มากกว่า" หรือ "น้อยกว่า"
                if (guess < winningNumber) {
                    std::cout << "\nSorry, the winning number is HIGHER than " << guess << ". (Score=" << score << ")\n\n";
                    // อัปเดตขอบเขตล่างของการทาย
                    if (guess >= lowerBound) {
                        lowerBound = guess + 1;
                    }
                } else { // guess > winningNumber
                    std::cout << "\nSorry, the winning number is LOWER than " << guess << ". (Score=" << score << ")\n\n";
                    // อัปเดตขอบเขตบนของการทาย
                    if (guess <= upperBound) {
                        upperBound = guess - 1;
                    }
                }
            }
        } while (guess != winningNumber && score > 0); // วนลูปจนกว่าจะทายถูกหรือคะแนนหมด
    }

    return 0; // จบการทำงานของโปรแกรม
}
