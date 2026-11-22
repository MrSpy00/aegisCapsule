# aegisCapsule

Hardware-accelerated Dynamic Island and desktop status capsule for Windows 10/11, written as a single-file Windhawk mod in C++, Direct2D, DirectWrite, and WASAPI (`60–240 FPS`).

**GitHub:** [MrSpy00/aegisCapsule](https://github.com/MrSpy00/aegisCapsule)

![License](https://img.shields.io/badge/license-MIT-black)
![Platform](https://img.shields.io/badge/platform-Windows%2010%2F11-0078D4)
![Engine](https://img.shields.io/badge/engine-Direct2D%20%2B%20DWrite%20%2B%20WASAPI-8b5cf6)
![FPS](https://img.shields.io/badge/fps-60--240%20FPS-00f5d4)

---

## Türkçe Açıklama

### aegisCapsule Nedir?

**aegisCapsule**, Windows masaüstünün üst çubuğunda çalışan, Direct2D ve DirectWrite ile donanım hızlandırmalı olarak çizilen tek dosyalık bir Windhawk modudur. Bildirim genişlemesi, medya kontrolü, WASAPI ses kaydı, Pomodoro sayacı, hızlı notlar ve temel sistem telemetrisi (CPU, RAM, GPU, disk, FPS) panellerini tek bir kapsül arayüzünde toplar.

### Özellikler

- **Tam Ekran Otomatik Gizleme (`Appearance.FullScreenDetection`):** Tam ekran oyun, video oynatıcı (YouTube, Netflix, VLC) veya sunum algılandığında kapsül otomatik olarak gizlenir, tam ekrandan çıkınca geri gelir.
- **Dinamik Bildirim Genişlemesi:** Gelen bildirim başlığına ve mesaj uzunluğuna göre kapsül yatayda genişler; uzun metinler için kayan yazı (marquee) kullanır.
- **Hatırlatıcılar:** Yapılandırılabilir su içme hatırlatıcısı (varsayılan 45 dk), 20-20-20 göz dinlendirme uyarısı, esneme ve uzun oturum bildirimleri.
- **WASAPI Ses Kaydedici:** Mikrofon girişinden 16-bit PCM WAV formatında doğrudan `Masaüstü\aegisCapsule_Recordings\` klasörüne kayıt alır; kayıt sırasında canlı ses dalgası gösterir.
- **Hızlı Notlar:** Sağ tık menüsündeki *Add Note from Clipboard* ile panodaki metni kapsül notlarına kaydeder.
- **Pomodoro Sayacı:** 25 dakika çalışma / 5 dakika mola döngüsü ve ilerleme halkası.
- **7 Sekmeli Genişletilmiş Görünüm:** Günlük Özet, Takvim & Saat, Hava Durumu (`wttr.in`), Donanım/Game Overlay, Hızlı Notlar, Pomodoro ve Yaşam Asistanı.
- **10 Renk Teması ve Kısmi Cam Efekti:** Direct2D tabanlı katmanlı cam görünümü, 10 renk teması ve eksen-hizalı kırpma.

### Kontroller

- **Fare Üzerine Gelme:** Kapsülü genişletir.
- **Fare Tekerleği:** Sekmeler arasında geçiş yapar.
- **Sol Tık:** Pomodoro başlat/durdur veya kayıt durdur.
- **Çift Tık:** Kapsülü açık modda sabitler.
- **Orta Tık:** Çalan medyayı Oynat / Duraklat.
- **Sağ Tık:** Hızlı kontrol menüsünü açar (ses kaydı, not ekleme, tema, şekil).

---

## English Description

### What is aegisCapsule?

**aegisCapsule** is a single-file Windhawk mod for Windows 10 and 11 written in native C++, Direct2D, DirectWrite, and WASAPI (`60–240 FPS`). It adds a top-bar capsule with dynamic notification expansion, media playback controls, microphone recording, a Pomodoro timer, clipboard quick notes, and basic hardware telemetry.

### Features

- **Full-Screen Auto-Hide:** Automatically hides during full-screen games, video players, or presentations and returns when exiting full screen.
- **Dynamic Notification Expansion:** Adjusts capsule width to match notification title and message length, with marquee scrolling for longer strings.
- **Wellness Prompts:** Configurable hydration reminder, 20-20-20 eye-break timer, posture reminder, and active-session break alerts.
- **WASAPI Voice Recorder:** Saves 16-bit PCM WAV microphone recordings to `%USERPROFILE%\Desktop\aegisCapsule_Recordings\` with a live waveform indicator.
- **Quick Notes:** Captures clipboard text into persistent quick notes from the context menu.
- **Pomodoro Timer:** 25/5 focus intervals with a progress ring.
- **7 Interactive Tabs:** Daily Briefing, Calendar, Weather (`wttr.in`), Hardware HUD, Quick Notes, Pomodoro, and Wellness Assistant.

---

## Installation / Kurulum

1. Install **Windhawk** from [windhawk.net](https://windhawk.net).
2. Open Windhawk > **Mods** > **Create / Install from file**.
3. Select `aegis-capsule.wh.cpp` (or `aegis-capsule.cpp`).
4. Windhawk compiles and loads the mod with the embedded `@compilerOptions`.

---

## Settings Reference / Ayar Rehberi

| Setting / Ayar | Description (EN) | Açıklama (TR) |
|---|---|---|
| `Appearance.FullScreenDetection` | Auto-hide capsule during games & fullscreen apps | Oyun ve tam ekran uygulamalarda otomatik gizlen |
| `Appearance.Position` | Placement (`top-center`, `top-left`, `top-right`, etc.) | Kapsülün ekrandaki yerleşimi |
| `Appearance.CornerStyle` | Shape (`pill`, `squircle`, `modern-box`, `sharp`) | Kapsül köşe geometrisi |
| `Optics.LiquidGlass` | Enable multi-layer glass rendering | Katmanlı cam efekti |
| `Optics.AccentGlow` | Ambient backglow conforming to capsule shape | Kapsül arkası ortam ışıması |
| `Optics.AccentColor` | Accent theme (`cyan`, `purple`, `emerald`, `crimson`, etc.) | Vurgu rengi teması |
| `Language` | Interface language (`auto`, `en`, `tr`) | Arayüz dili |
| `Weather.City` | Custom city name (blank for IP auto-detect) | Özel şehir adı (boşsa IP üzerinden tespit) |

---

## License

MIT License — see [LICENSE](LICENSE).
