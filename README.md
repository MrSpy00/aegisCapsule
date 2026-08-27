# aegisCapsule — v0.0.1

> **Next-generation Liquid Glass Dynamic Island for Windows.** Native Direct2D, 60–240 FPS, zero-bloat single-file Windhawk mod by **aegis**. GitHub: **MrSpy00/aegisCapsule**.

![License](https://img.shields.io/badge/license-MIT-black)
![Version](https://img.shields.io/badge/version-0.0.1-4cc9f0)
![Platform](https://img.shields.io/badge/platform-Windows%2010%2F11-0078D4)
![Engine](https://img.shields.io/badge/engine-Direct2D%20%2B%20DWrite-8b5cf6)

---

## 💎 Nedir?

**aegisCapsule**, Windows masaüstünü iOS Dynamic Island / Apple Vision Pro estetiğiyle buluşturan ultra-akıcı bir kapsül. Tek dosya (`aegisCapsule.cpp`), donanım hızlandırmalı, 15+ modül, tam özelleştirilebilir Liquid Glass optik motoru ve fizik tabanlı spring animasyonlar.

- **Tek dosya, sıfır bağımlılık şişmesi** — Windhawk ile `windhawk.exe` içinde çalışır.
- **En düşük donanımda bile akıcı** — düşük güçlü cihazlarda 30 FPS power-saver'a otomatik düşer.
- **Her şey ayarlanabilir** — konumdan gölge yayılımına, waveform bar sayısından privacy dot yarıçapına kadar 50+ ayar.

---

## ✨ Öne Çıkanlar

### Liquid Glass Optik Motoru
- Çok katmanlı frosted glass, linear sheen gradient, hareketli caustic shimmer, 1px specular highlight, refraction rim, accent glow halo
- **Kontroller:** `LiquidGlass`, `LiquidGlassIntensity(0-100)`, `GlassSheen`, `GlassCaustics` + `CausticsSpeed(0-5)`, `GlassSpecular` + `TopHighlightOpacity`, `GlassRefractionRim` + `RimThickness`, `AccentGlow` + `Intensity/Radius`, `SoftShadow` + `Spread/YOffset/Softness`

### Akıllı Dashboard'lar
| Modül | Açıklama |
|---|---|
| **Media Controller** | Albüm artı, titreşimli waveform (`BarCount 8-32`, `Gap`), scrubber, prev/play/next hit-test düzeltildi |
| **Calendar & Time** | Bugün vurgulu ızgara, `GetDayOfWeek` düzeltmesi, brush opacity reset |
| **Weather** | `wttr.in` — temp/feels/wind/humidity, `WeatherUpdateMinutes(5-60)`, auto IP |
| **Game & Hardware Bar** | FPS/CPU/RAM/GPU/Disk, PDH GPU Engine 3D filtre |
| **Idle Pill** | Saat + hava durumu, opsiyonel `ShowMetricsInIdle` micro-chip'ler |
| **Privacy Shield** | Mic (turuncu) / Cam (yeşil) pulsing halo + specular nokta, `PrivacyDotSize` |
| **Clipboard / Notification / Volume / CapsLock / Device / Battery / Progress** | Süre ayarlı TTL'ler, 64px icon, UWP toast |

### Fizik & Performans
- Per-kind spring: `Bouncy / Smooth / Snappy / Stiff` × `AnimationSpeed(0.65-5.0x)` — `stiffness/damping` ayrı
- Hover scale `HoverScalePercent(100-115%)`, split gap `SplitGap(4-32px)`, nudge `NudgeOffsetPx(0-20)`
- `FrameRateTarget 30/60/120/144/240` + `LowPowerMode` idle throttling
- Brush cache, text format scale cache, `PositionOverlayWindow` jitter guard, mutex-safe `g_settings` snapshot, `Modulo` tab güvenliği

---

## ⚙️ Kurulum

1. **Windhawk** kur → `https://windhawk.net`
2. Modu içe aktar: `aegisCapsule.cpp` dosyasını Windhawk > Mods > Install from file
3. Derleyici seçenekleri otomatik: `-lole32 -loleaut32 -lshcore -ld2d1 -ldwrite -ldwmapi ...`

> GitHub'dan klonlamak için:
> ```bash
> git clone https://github.com/MrSpy00/aegisCapsule.git
> ```

---

## 🎛️ Ayarlar (Windhawk > Mod Settings)

**Appearance & Geometry:** `Position(top-center/.../center)`, `TargetMonitor(primary/1-5/follow)`, `OffsetX/Y`, `EdgeMargin`, `SizeScale(0.5-3.0x)`, `CornerStyle(pill/squircle/modern-box/sharp/custom)` + `CustomCornerRadius`, `Collapsed/Expanded Width/Height`, `AutoHideIdleSeconds(-1/0/3-60)`, `UnhideOnHover`, `ExpandOnHover`, `AlwaysOnTop`, `AutoDpiScale`, `ClickThroughIdle`

**Optics & Liquid Glass:** Yukarıdaki Liquid Glass başlığına bak.

**Colors & Theming:** `AccentColorMode(auto/system/custom)` + `CustomAccentHex(#RRGGBBAA)`, `PillBgColor`, `TextPrimary/Secondary`, `TintIntensity`, `PillOpacity`, 10 tema preset (OLED Black, Liquid Silver/Night/Aurora, Pure Glass...)

**Physics & Performance:** `AnimationSpeed`, `SpringStyle`, `FrameRateTarget`, `LowPowerMode`

**Modules & Features:** Her modül toggle + `Notification/Clipboard/Volume/CapsLock/Device Duration`, `WeatherCity`, `WeatherFahrenheit`, `ShowMetricsInIdle`

**Fine Tuning & Advanced (Yeni):** `SplitGap`, `HoverScalePercent`, `NudgeOffsetPx`, `WaveformBarCount/Gap`, `ProgressRingThickness`, `PaginationDotSize`, `PrivacyDotSize`, `TopHighlightOpacity`, `RimThickness`, `ShadowSpread/YOffset`, `CausticsSpeed`, `ContentFadeOnResize`, `UseDwmBlurBehind(experimental)`, `WeatherUpdateMinutes`

Sağ tık menüsü: Pinned Expanded, Game Overlay, ExpandOnHover, Liquid Glass/Glow, MetricsInIdle, Corner Shape, Opacity, 10 tema — anında `Wh_SetIntValue` ile.

---

## 🖱️ Etkileşimler

- **Hover** → expand (veya `ExpandOnHover=off` ise tıkla)
- **Çift tık** → pinned expand toggle
- **Orta tık** → play/pause
- **Scroll** → idle/media tab değiştir (Modulo güvenli)
- **Media kontrolleri** → prev/play/next + scrubber drag (unscaled hit-test düzeltildi, `SetCapture`)
- **Sağ tık** → power menu

---

## 🐛 Düzeltmeler (v0.0.1)

- `DrawSoftShadow` gerçek çok katmanlı gölge (önce boştu)
- `EnsureTextFormats` scale ile çarpım (DPI fix)
- `DrawAccentGlow` aktif, `g_settings` mutex-safe snapshot
- Media scrubber `WM_LBUTTON*` unscaled koordinat, `g_idleTab` Modulo, `calHeader` opacity reset, brush cache, weather thread lock, `ColorFromHex` #RRGGBBAA, `PositionOverlayWindow` jitter guard dahil.

---

## 🔧 Geliştirme

```bash
# Tek dosya — başka dosya oluşturma
# Derleme Windhawk içinde otomatik, manuel test için:
# Windhawk > Mods > aegisCapsule > Settings değiştir → anında hot-reload
```

**Yapımcı:** `aegis` · **GitHub:** `MrSpy00/aegisCapsule` · **Lisans:** MIT

---

> PR ve issue'lar açık — `aegis` ile geliştirilmeye devam ediyor.
