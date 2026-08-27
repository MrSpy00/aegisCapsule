# aegisCapsule — Liquid Glass Dynamic Island for Windows

> **Next-generation Liquid Glass Dynamic Island & Living Personal Assistant for Windows 10/11.**  
> Native Direct2D, 60–240 FPS, ultra-fluid spring physics, zero-bloat single-file Windhawk mod by **aegis**.  
> **GitHub:** [MrSpy00/aegisCapsule](https://github.com/MrSpy00/aegisCapsule)

![License](https://img.shields.io/badge/license-MIT-black)
![Platform](https://img.shields.io/badge/platform-Windows%2010%2F11-0078D4)
![Engine](https://img.shields.io/badge/engine-Direct2D%20%2B%20DWrite%20%2B%20WASAPI-8b5cf6)
![FPS](https://img.shields.io/badge/fps-60--240%20FPS-00f5d4)

---

## 🇹🇷 Türkçe Açıklama

### 💎 aegisCapsule Nedir?
**aegisCapsule**, Windows masaüstünü Apple iOS Dynamic Island ve Vision Pro Liquid Glass estetiğiyle buluşturan, donanım hızlandırmalı ve ultra-akıcı bir masaüstü kapsülüdür. 

Sıradan bir bildirim çubuğu veya araç takımı olmanın ötesinde; **tam teşekküllü bir kişisel asistan**, **ses kayıt cihazı**, **Pomodoro odak sayacı**, **hızlı not defteri** ve **canlı sistem monitörü** olarak çalışır.

---

### ✨ Öne Çıkan Özellikler

#### 1. 🎬 Tam Ekran Otomatik Gizlenme (Full-Screen Auto-Hide)
- Oyun oynarken, tam ekran film izlerken (YouTube, Netflix, VLC vb.) veya sunum yaparken kapsül otomatik olarak tespit eder ve tamamen kapanır.
- Tam ekrandan çıkıldığında akıcı spring animasyonuyla geri gelir.
- İstenirse `Appearance.FullScreenDetection` ayarı üzerinden açılıp kapatılabilir.

#### 2. 🪄 Dinamik Genişleyen Bildirim Çubuğu (Dynamic Island Expansion)
- Bildirim geldiğinde sabit boyuta sıkışmak veya yazının kesilmesi yerine, başlık ve mesaj uzunluğuna göre kapsül yatayda otomatik olarak genişler ve tüm metni eksiksiz gösterir.
- Kayan yazı (marquee) moduyla uzun metinler akıcı şekilde akar.

#### 3. 🌿 Yaşayan Kapsül & Kişisel Sağlık Asistanı (Living Wellness Assistant)
- **Su İçme Hatırlatıcısı (Hydration Alert):** Belirlenen aralıklarla (varsayılan 45 dk) su içmenizi hatırlatır.
- **20-20-20 Göz Dinlendirme:** Her 20 dakikada bir 20 fit uzağa 20 saniye bakma uyarısı verir.
- **Duruş ve Esneme:** Uzun oturmalarda omuz ve omurga esnetme tavsiyesi gönderir.
- **Aktif Oturum Uyarısı:** Bilgisayar başında kesintisiz 2 saatten fazla kaldığınızda mola vermenizi önerir.

#### 4. 🎙️ Gelişmiş Akıllı Ses Kaydedici (WASAPI Voice Recorder)
- Windows Core Audio (WASAPI) motoru ile mikrofonunuzdan doğrudan stüdyo kalitesinde 16-bit PCM WAV kaydı alır.
- Kayıtları otomatik olarak `Masaüstü\aegisCapsule_Recordings\` klasörüne tarih-saat etiketiyle kaydeder.
- Kayıt esnasında kapsül üzerinde canlı ses dalgası (waveform) ve kırmızı kayıt animasyonu gösterilir.

#### 5. 📝 Hızlı Notlar & Scratchpad (Quick Notes)
- Aklınıza gelen fikirleri veya kopyaladığınız metinleri anında kapsüle not olarak ekleyin.
- Sağ tık menüsünden *"Add Note from Clipboard"* seçeneğiyle panodaki metin anında kaydedilir ve Kapsül Notlar sekmesinde listelenir.

#### 6. 🍅 Pomodoro Odak Sayacı (Focus Timer)
- 25 dakika çalışma, 5 dakika mola döngüleriyle üretkenliğinizi zirveye taşır.
- Kapsüle tıklayarak veya sağ tık menüsünden başlatılır/duraklatılır. Süre bittiğinde özel bildirimle uyarır.

#### 7. 📑 6 Sekmeli Gelişmiş Genişletilebilir Dashboard
Genişletilmiş modda fare tekerleğiyle veya tıklayarak 6 farklı sekmeye geçiş yapabilirsiniz:
1. **📅 Takvim & Saat:** Ay görünümü, bugün vurgusu ve detaylı tarih.
2. **⛅ Hava Durumu & Atmosfer:** wttr.in tabanlı sıcaklık, rüzgar hızı, yönü, nem ve hissedilen sıcaklık.
3. **🎮 Donanım & Game Overlay:** CPU, RAM, GPU, FPS ve Disk kullanım grafikleri.
4. **📝 Hızlı Notlar:** Son alınan notların listesi.
5. **🍅 Pomodoro:** Odak döngüsü sayacı ve ilerleme halkası.
6. **🌿 Yaşam Asistanı:** Sistem çalışma süresi ve sağlık metrikleri.

#### 8. 💎 Kusursuz Liquid Glass Optik Motoru & Görsel Temizlik
- Kapsül dışındaki tüm karanlık leke ve gölge taşmaları giderilmiştir.
- Çok katmanlı frosted glass, yumuşak kenar ışıması (ambient glow), specular yansımalar ve 10 farklı renk teması.

---

### 🖱️ Kontroller & Kısayollar

- **Fare Üzerine Gelme (Hover):** Kapsülü genişletir (veya ayardan tıklama moduna alınabilir).
- **Fare Tekerleği (Scroll):** Standart yönünde sekmeler arasında ileri/geri geçiş yapar (Yukarı = Önceki, Aşağı = Sonraki).
- **Sol Tık:** Pomodoro başlat/durdur veya sekmeler arası geçiş yap. Kayıt sırasında kaydı durdurur.
- **Çift Tık:** Kapsülü sürekli açık (Pinned Expanded) moduna sabitler.
- **Orta Tık:** Çalan medyayı Oynat / Duraklat.
- **Sağ Tık:** Hızlı kontrol menüsünü açar (Ses kaydı, Not ekleme, Tema değiştirme, Şekil ayarı).

---

## 🇬🇧 English Description

### 💎 What is aegisCapsule?
**aegisCapsule** brings the pinnacle of Apple iOS Dynamic Island and Vision Pro Liquid Glass aesthetics to Windows 10 and 11. Built with pure hardware-accelerated Direct2D and DirectWrite in a single zero-bloat file (`aegis-capsule.cpp`), it runs smoothly at 60 to 240 FPS.

Beyond a simple status pill, it is a **complete personal desktop companion**, featuring a **WASAPI voice recorder**, **Pomodoro timer**, **quick notes scratchpad**, **living wellness assistant**, and **hardware telemetry**.

---

### ✨ Core Highlights

1. **Full-Screen Auto-Hide:** Automatically hides when you play full-screen games, watch full-screen videos (YouTube, Netflix, VLC), or give presentations. Smoothly reappears when exiting fullscreen.
2. **Dynamic Island Expansion:** Automatically scales its width dynamically according to the notification title and message length.
3. **Living Personal Assistant:** Built-in wellness reminders for hydration, 20-20-20 eye strain relief, posture correction, and continuous PC uptime tracking.
4. **Smart Voice Recorder:** One-click studio quality 16-bit PCM WAV audio capture via WASAPI directly to `%USERPROFILE%\Desktop\aegisCapsule_Recordings\`.
5. **Quick Notes Scratchpad:** Store instant notes and thoughts directly from the clipboard or menu with persistent storage.
6. **Pomodoro Focus Timer:** 25/5 interval productivity clock with visual progress arc and session tracking.
7. **6 Interactive Dashboard Tabs:** Seamlessly cycle through Calendar, Weather, Hardware HUD, Quick Notes, Pomodoro, and Living Assistant.
8. **Liquid Glass Multi-Layer Optics:** Cleaned ambient backglow, specular highlight, refraction rim, and zero border bleeding.

---

## ⚙️ Installation & Setup / Kurulum

1. Download and install **Windhawk**: [https://windhawk.net](https://windhawk.net)
2. Open Windhawk > **Mods** > **Create / Install from file**.
3. Select `aegis-capsule.cpp`.
4. Windhawk will automatically compile and launch the mod with all required compiler options.

---

## 🎛️ Settings Reference / Ayar Rehberi

| Setting / Ayar | Description (EN) | Açıklama (TR) |
|---|---|---|
| `Appearance.FullScreenDetection` | Auto-hide capsule during games & fullscreen apps | Oyun ve tam ekran uygulamalarda otomatik gizlen |
| `Appearance.Position` | Placement (`top-center`, `top-left`, `top-right`, etc.) | Kapsülün ekrandaki yerleşimi |
| `Appearance.CornerStyle` | Shape (`pill`, `squircle`, `modern-box`, `sharp`) | Kapsül köşe ve geometrisi |
| `Optics.LiquidGlass` | Enable multi-layer frosted glass optics | Çok katmanlı sıvı cam efekti |
| `Optics.AccentGlow` | Ambient backglow conforming to capsule shape | Kapsül arkasındaki yumuşak ortam ışıması |
| `Modules.NotificationAutoExpand` | Dynamically expand width for notifications | Bildirim uzunluğuna göre genişliği otomatik büyüt |
| `Assistant.EnableWellnessReminders` | Enable water, eye rest, and uptime reminders | Su içme, göz dinlendirme ve sağlık hatırlatıcıları |
| `Tools.PomodoroWorkMinutes` | Pomodoro focus duration (default: 25 min) | Pomodoro çalışma süresi (varsayılan: 25 dk) |
| `Tools.VoiceRecordingFolder` | Custom folder for recorded WAV voice notes | Ses kayıtlarının kaydedileceği özel klasör |

---

## 📜 License & Credits

- **Author:** aegis (`MrSpy00`)
- **License:** MIT License
- **Repository:** [https://github.com/MrSpy00/aegisCapsule](https://github.com/MrSpy00/aegisCapsule)
