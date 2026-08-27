// ==WindhawkMod==
// @id              aegis-capsule
// @name            aegisCapsule
// @description     aegisCapsule - Next-generation fluid Liquid Glass dynamic capsule for Windows desktops with advanced hardware metrics, media controls, intelligent dashboards, and buttery-smooth physics animations.
// @version         0.0.1
// @author          aegis
// @github          https://github.com/MrSpy00/aegisCapsule
// @include         windhawk.exe
// @compilerOptions -lole32 -loleaut32 -lshcore -ld2d1 -ldwrite -ldwmapi -lgdi32 -luser32 -lshell32 -lruntimeobject -lwindowscodecs -lavrt -lsetupapi -lwinhttp -lpdh
// @license         MIT
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*
# aegisCapsule v0.0.1

A cutting-edge, ultra-fluid desktop dynamic capsule companion featuring modern Liquid Glass optics, Apple Vision Pro aesthetics, intelligent hardware dashboards, media controls, and buttery-smooth physics animations. Built natively with hardware-accelerated Direct2D rendering for an uncompromising 60-240 FPS experience with near-zero CPU usage.

---

## 💎 Liquid Glass & Optical Design Engine
- **Multi-Layer Optics:** Dynamic specular highlights, soft ambient drop shadows, light refraction rims, and subtle animated shimmer caustics.
- **Customizable Corner Geometry:** Switch freely between Full Pill, Vision Squircle, Modern 8px Box, Sharp Minimal Box, or custom radius (0-60px).
- **Adaptive Accent Illumination:** Dynamic ambient backglow reacting to album artwork or system accent colors.
- **Ultra-Tuned Micro-Physics Spring:** Independent damping and stiffness tailored for media, alerts, and idle states.

## 🚀 Modules & Smart Dashboards
- **Media Controller:** Live album art, track info, responsive frequency-colored waveform, interactive seek bar, and transport controls.
- **Calendar & Time:** Perfectly aligned monthly calendar with today highlighting and active date grid.
- **Real-Time Weather:** Live weather stats powered by wttr.in (temp, feels-like, humidity, wind speed, condition icons).
- **Game & Hardware Bar:** Real-time FPS, CPU, RAM, GPU, and Disk utilization overlays.
- **Idle Pill & Micro-Metrics:** Minimal clock, weather summary, and optional collapsed CPU/RAM/Battery micro-chips.
- **Hardware Privacy Shield:** Pulsing visual indicators for active microphone (orange) and webcam (green) sessions.
- **High-Fidelity Clipboard & Notifications:** 64px crisp executable icon extraction with UWP toast parsing.

---

## ⚙️ Extensive Customization & Placement
- **Full Screen Freedom:** Anchor to Top-Center, Top-Left, Top-Right, Bottom-Center, Bottom-Left, Bottom-Right, or Center, with fine-grained X/Y pixel offsets and boundary margins.
- **Customizable Dimensions:** Adjust collapsed and expanded width/height, scale multiplier (0.5x - 3.0x).
- **Auto-Hide & Hover:** Hide instantly, after X seconds, or never; toggle hover expansion vs click expansion.
- **Right-Click Power Menu:** Instant access to curated themes (OLED Black, Liquid Silver, Liquid Aurora, Liquid Night, Pure Glass, etc.), transparency sliders, and live style toggles.
- **Multi-Monitor:** Place on Primary display, secondary monitors, or activate "Follow Mouse" mode.
*/
// ==/WindhawkModReadme==

// ==WindhawkModSettings==
/*
- Appearance:
  - Position: top-center
    $name: Position
    $description: Where aegisCapsule should appear on your screen.
    $options:
      - top-center: Top Center
      - top-left: Top Left
      - top-right: Top Right
      - bottom-center: Bottom Center
      - bottom-left: Bottom Left
      - bottom-right: Bottom Right
      - center: Screen Center
  - TargetMonitor: primary
    $name: Target Monitor
    $description: Select the screen to display the capsule. Falls back to Primary Monitor if unavailable.
    $options:
      - 'primary': Primary Monitor
      - '1': Display 1
      - '2': Display 2
      - '3': Display 3
      - '4': Display 4
      - '5': Display 5
      - 'follow': Follow Mouse (Active Monitor)
  - OffsetX: 0
    $name: Offset X (px)
    $description: Horizontal fine-tuning in pixels. Positive moves right, negative moves left.
  - OffsetY: 0
    $name: Offset Y (px)
    $description: Vertical fine-tuning in pixels. Positive moves down, negative moves up.
  - EdgeMargin: 8
    $name: Screen Edge Margin (px)
    $description: Distance from the edge of the monitor.
  - SizeScale: '1.0'
    $name: Overall Size Scale
    $description: Adjust global UI size scale multiplier.
    $options:
      - '0.5': 0.5x (Mini)
      - '0.6': 0.6x
      - '0.7': 0.7x
      - '0.8': 0.8x (Compact)
      - '0.9': 0.9x
      - '1.0': 1.0x (Standard)
      - '1.1': 1.1x
      - '1.2': 1.2x (Medium)
      - '1.3': 1.3x
      - '1.5': 1.5x (Large)
      - '1.8': 1.8x
      - '2.0': 2.0x (Extra Large)
      - '2.5': 2.5x (Ultra)
      - '3.0': 3.0x (Mega)
  - CornerStyle: pill
    $name: Corner Roundness & Shape
    $description: Choose how round or sharp the capsule edges appear.
    $options:
      - pill: Full Pill (Continuous Round Capsule)
      - squircle: Vision Squircle (Smooth Rounded Rectangle)
      - modern-box: Modern Box (8px Corner Radius)
      - sharp: Sharp Box (0px Corner Radius - Sleek Rectangle)
      - custom: Custom Radius (Use Custom Corner Radius below)
  - CustomCornerRadius: 18
    $name: Custom Corner Radius (px)
    $description: Applied when Corner Roundness is set to Custom. (0 = sharp square, 50 = full circle)
  - CollapsedWidth: 170
    $name: Collapsed Idle Width (px)
    $description: Width of the minimal idle capsule before size scaling. Default is 170.
  - CollapsedHeight: 36
    $name: Collapsed Idle Height (px)
    $description: Height of the minimal idle capsule before size scaling. Default is 36.
  - ExpandedWidth: 380
    $name: Expanded Dashboard Width (px)
    $description: Width of the expanded dashboard before size scaling. Default is 380.
  - ExpandedHeight: 184
    $name: Expanded Dashboard Height (px)
    $description: Height of the expanded dashboard before size scaling. Default is 184.
  - AutoHideIdleSeconds: '0'
    $name: Auto-hide idle capsule
    $description: Hide the idle capsule after inactivity. -1 hides instantly, 0 keeps it always visible.
    $options:
      - '-1': Hide instantly (Invisible until triggered)
      - '0': Never hide (Always visible)
      - '3': Hide after 3 seconds
      - '5': Hide after 5 seconds
      - '10': Hide after 10 seconds
      - '15': Hide after 15 seconds
      - '30': Hide after 30 seconds
      - '60': Hide after 60 seconds
  - UnhideOnHover: true
    $name: Unhide on hover
    $description: Allow a hidden capsule to reappear when hovering near its anchor.
  - ExpandOnHover: true
    $name: Expand on hover
    $description: Expand the capsule automatically when hovered. If disabled, click to expand.
  - AlwaysOnTop: true
    $name: Always on top
    $description: Keeps aegisCapsule above all other windows.
  - AutoDpiScale: true
    $name: Auto DPI scaling
    $description: Automatically scales font sizes and metrics to match monitor DPI.
  - ClickThroughIdle: false
    $name: Click-through when idle
    $description: Let mouse clicks pass through the minimal idle capsule to windows beneath it.
  $name: Appearance & Geometry
- Optics:
  - LiquidGlass: true
    $name: Liquid Glass Optical Engine
    $description: Master switch for multi-layer frosted glass, caustics, and refraction.
  - LiquidGlassIntensity: 80
    $name: Liquid Glass Intensity
    $description: 0 to 100. Controls the prominence of the glass sheen and refraction rim.
  - GlassSheen: true
    $name: Frosted Glass Gradient Sheen
    $description: Renders a smooth vertical ambient light sheen across the capsule face.
  - GlassCaustics: true
    $name: Animated Caustic Light Wave
    $description: Renders an ultra-subtle animated sinusoidal light shimmer across the surface.
  - GlassSpecular: true
    $name: 1px Top Specular Highlight
    $description: Adds a crisp, elegant top rim reflection line.
  - GlassRefractionRim: true
    $name: Edge Refraction Border
    $description: Simulates optical refraction along the outer capsule perimeter.
  - AccentGlow: true
    $name: Ambient Accent Glow
    $description: Dynamic breathing ambient colored halo behind the capsule.
  - AccentGlowIntensity: 80
    $name: Accent Glow Intensity
    $description: 0 to 100. Controls the brightness of the ambient glow.
  - AccentGlowRadius: 32
    $name: Accent Glow Radius (px)
    $description: Spread distance of the ambient colored halo.
  - SoftShadow: true
    $name: Multi-Pass Soft Drop Shadow
    $description: Progressive soft atmospheric drop shadow beneath the capsule.
  - ShadowSoftness: 70
    $name: Shadow Softness
    $description: 0 to 100. Controls shadow blur and depth.
  $name: Optics & Liquid Glass
- Themes:
  - AccentColorMode: auto
    $name: Accent Color Mode
    $description: How the glowing accent color is chosen. Auto dynamically samples album art.
    $options:
      - auto: Auto (from album art / dynamic)
      - system: Windows System Accent
      - custom: Custom Hex Color
  - CustomAccentHex: "#4cc9f0"
    $name: Custom Accent Hex
    $description: Hex color for accent mode (#RRGGBB or #RRGGBBAA).
  - PillBgColor: "#0D0D0F"
    $name: Capsule Background Color
    $description: Hex color for background (#RRGGBB or #RRGGBBAA).
  - TextPrimaryColor: "#F7F7F7"
    $name: Primary Text Color
    $description: Hex color for track titles and primary metrics.
  - TextSecondaryColor: "#888888"
    $name: Secondary Text Color
    $description: Hex color for artist names and muted labels.
  - TintIntensity: 72
    $name: Background Tint Depth
    $description: 0 to 100. Controls the depth of the dark base tint.
  - PillOpacity: 96
    $name: Capsule Transparency
    $description: 10 to 100. Lower values make the capsule glass more translucent.
  $name: Colors & Theming
- Performance:
  - AnimationSpeed: normal
    $name: Animation Speed
    $description: Transition speed multiplier.
    $options:
      - slow: Slow (0.65x)
      - normal: Normal (1.0x)
      - fast: Fast (1.35x)
      - instant: Instant (5.0x Snappy)
  - SpringStyle: bouncy
    $name: Spring Physics Dynamic
    $description: Motion curve for capsule expansions and morphs.
    $options:
      - bouncy: Bouncy (Apple Vision Pro fluid bounce)
      - smooth: Smooth (Critically damped gentle glide)
      - snappy: Snappy (High tension responsive snap)
      - stiff: Stiff (Minimal overshoot)
  - FrameRateTarget: '60'
    $name: Target Refresh Rate
    $description: Maximum render loop refresh rate.
    $options:
      - '30': 30 FPS (Power Saver)
      - '60': 60 FPS (Standard Smooth)
      - '120': 120 FPS (High Refresh)
      - '144': 144 FPS (Ultra Refresh)
      - '240': 240 FPS (Extreme Esports)
  - LowPowerMode: false
    $name: Adaptive Power Saver
    $description: Automatically throttles idle rendering and disables caustics when on battery.
  $name: Physics & Performance
- Modules:
  - Media: true
    $name: Media module
    $description: Shows album art, song info, scrubber, and playback controls when music is playing.
  - Notification: true
    $name: Notification module
    $description: Shows rich Windows toast notifications and banner popups in the capsule.
  - Clipboard: true
    $name: Clipboard module
    $description: Shows a quick preview of text or images copied to clipboard.
  - Battery: true
    $name: Battery module
    $description: Shows alerts when battery is low or charger is connected.
  - Progress: true
    $name: Progress module
    $description: Shows a progress ring around the capsule for file transfers or downloads.
  - Volume: true
    $name: Volume OSD module
    $description: Shows instant volume bar and mute status on system volume change.
  - CapsLock: true
    $name: Caps/Num Lock OSD module
    $description: Shows keycap status indicator when Caps Lock or Num Lock is pressed.
  - Device: true
    $name: Device connection OSD module
    $description: Shows alert when USB or Bluetooth devices are connected or removed.
  - GameOverlay: false
    $name: Enable game overlay mode
    $description: Replaces the clock with live stats like FPS, CPU, GPU, and RAM usage.
  - ShowMetricText: true
    $name: Show labels in metric chips
    $description: Adds text labels (like "CPU") inside the game overlay bars.
  - ShowMetricsInIdle: false
    $name: Show micro-metrics in idle capsule
    $description: Displays small CPU and RAM chips in the collapsed idle capsule view.
  - WeatherCity: ""
    $name: Weather City (Optional)
    $description: Enter your city (e.g. London, Istanbul). Leave blank for auto IP geolocation.
  - WeatherFahrenheit: false
    $name: Use Fahrenheit
    $description: Display weather temperature and wind speed in imperial units.
  - NotificationDuration: "4.0"
    $name: Notification display duration
    $description: How long (in seconds) to display new notifications.
    $options:
      - '2.0': 2.0s
      - '3.0': 3.0s
      - '4.0': 4.0s
      - '6.0': 6.0s
      - '8.0': 8.0s
  - ClipboardDuration: "2.5"
    $name: Clipboard display duration
    $description: How long (in seconds) to display clipboard copy popups.
    $options:
      - '1.5': 1.5s
      - '2.5': 2.5s
      - '4.0': 4.0s
      - '6.0': 6.0s
  - VolumeDuration: "1.8"
    $name: Volume display duration
    $description: How long (in seconds) to display volume popups.
    $options:
      - '1.2': 1.2s
      - '1.8': 1.8s
      - '2.5': 2.5s
      - '3.5': 3.5s
  - CapsLockDuration: "1.5"
    $name: Caps Lock display duration
    $description: How long (in seconds) to display Caps/Num Lock popups.
    $options:
      - '1.0': 1.0s
      - '1.5': 1.5s
      - '2.5': 2.5s
  - DeviceDuration: "3.0"
    $name: Device alert display duration
    $description: How long (in seconds) to display USB/Device connect alerts.
    $options:
      - '2.0': 2.0s
      - '3.0': 3.0s
      - '4.5': 4.5s
  $name: Modules & Features
- FineTuning:
  - SplitGap: 12
    $name: Split pill gap (px)
    $description: Gap between two pills in Split mode before scaling. 4-32px.
  - HoverScalePercent: 102
    $name: Hover scale (%)
    $description: Pill scale on hover/pinned (100 = no scale, 115 = 15% larger). 100-115.
  - NudgeOffsetPx: 8
    $name: Nudge distance (px)
    $description: Vertical bounce distance on new event. 0-20px (0 disables nudge).
  - WaveformBarCount: 22
    $name: Waveform bar count
    $description: Number of bars in audio waveform. 8-32.
  - WaveformGapPx: '2.5'
    $name: Waveform bar gap (px)
    $description: Gap between waveform bars before scaling.
  - ProgressRingThickness: '2.8'
    $name: Progress ring thickness (px)
    $description: Thickness of progress ring stroke. 1.0-6.0.
  - PaginationDotSize: '2.5'
    $name: Pagination dot radius (px)
    $description: Radius of idle/media pagination dots before scaling.
  - PrivacyDotSize: '3.8'
    $name: Privacy dot radius (px)
    $description: Radius of mic/camera privacy dots before scaling.
  - TopHighlightOpacity: 35
    $name: Top specular highlight opacity
    $description: Opacity of 1px top rim highlight (0-100).
  - RimThickness: '0.9'
    $name: Refraction rim thickness (px)
    $description: Stroke thickness of outer refraction border.
  - ShadowSpreadPx: 10
    $name: Shadow spread (px)
    $description: Maximum spread of soft drop shadow. 0-24.
  - ShadowYOffsetPx: 4
    $name: Shadow Y offset (px)
    $description: Vertical offset of drop shadow. 0-12.
  - CausticsSpeed: '1.3'
    $name: Caustics animation speed
    $description: Speed multiplier for glass caustics wave. 0.0-3.0 (0 = frozen).
  - ContentFadeOnResize: true
    $name: Content fade on resize
    $description: Fade pill content alpha during morph (smoother transitions).
  - UseDwmBlurBehind: false
    $name: DWM blur behind (experimental)
    $description: Enable real backdrop blur via DwmEnableBlurBehindWindow. May affect performance.
  - WeatherUpdateMinutes: 10
    $name: Weather update interval (minutes)
    $description: Weather fetch interval. 5-60 minutes.
  $name: Fine Tuning & Advanced
*/
// ==/WindhawkModSettings==

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif

#include <windows.h>
#include <unknwn.h>
#include <dwmapi.h>
#include <shellapi.h>
#include <setupapi.h>
#include <dbt.h>
#include <d2d1.h>
#include <dwrite.h>
#include <wincodec.h>
#include <shcore.h>
#include <windowsx.h>
#include <audioclient.h>
#include <audiopolicy.h>
#include <endpointvolume.h>
#include <mmdeviceapi.h>
#include <mmreg.h>
#include <objbase.h>
#include <wrl/client.h>
#include <uiautomation.h>
#include <winhttp.h>
#include <pdh.h>
#include <pdhmsg.h>

#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cwchar>
#include <cstring>
#include <mutex>
#include <optional>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include <winrt/base.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Media.Control.h>
#include <winrt/Windows.Storage.Streams.h>
#if __has_include(<winrt/Windows.UI.Notifications.Management.h>) && \
    __has_include(<winrt/Windows.UI.Notifications.h>)
#define AEGIS_CAPSULE_HAS_USER_NOTIFICATION_LISTENER 1
#include <winrt/Windows.ApplicationModel.h>
#include <winrt/Windows.UI.Notifications.h>
#include <winrt/Windows.UI.Notifications.Management.h>
#else
#define AEGIS_CAPSULE_HAS_USER_NOTIFICATION_LISTENER 0
#endif

using Microsoft::WRL::ComPtr;
using namespace std::chrono_literals;

namespace {

constexpr wchar_t kWindowClass[] = L"aegisCapsule_Overlay";
[[maybe_unused]] constexpr UINT WM_APP_LAYOUT_CHANGED = WM_APP + 0x442;
constexpr UINT WM_APP_NEW_EVENT = WM_APP + 0x443;
constexpr float kRenderPadX = 32.0f;
constexpr float kRenderPadY = 24.0f;

enum class IslandKind {
    Idle,
    Media,
    Progress,
    Clipboard,
    Notification,
    Volume,
    BatteryLow,
    CapsLock,
    Device,
    Split,
};

enum class CornerStyle {
    Pill,
    Squircle,
    ModernBox,
    Sharp,
    Custom,
};

enum class Position {
    TopCenter,
    TopLeft,
    TopRight,
    BottomCenter,
    BottomLeft,
    BottomRight,
    Center,
};

enum class SpringStyle {
    Bouncy,
    Smooth,
    Snappy,
    Stiff,
};

enum class AccentMode {
    Auto,
    System,
    Custom,
};

struct Settings {
    Position position = Position::TopCenter;
    int targetMonitor = 0;
    int offsetX = 0;
    int offsetY = 0;
    int edgeMargin = 8;
    float sizeScale = 1.0f;
    CornerStyle cornerStyle = CornerStyle::Pill;
    float customCornerRadius = 18.0f;
    float collapsedWidth = 170.0f;
    float collapsedHeight = 36.0f;
    float expandedWidth = 380.0f;
    float expandedHeight = 184.0f;
    int autoHideIdleSeconds = 0;
    bool unhideOnHover = true;
    bool alwaysOnTop = true;
    bool expandOnHover = true;
    bool autoDpiScale = true;
    bool clickThroughIdle = false;

    // Optics & Liquid Glass
    bool liquidGlass = true;
    float liquidGlassIntensity = 0.80f;
    bool glassSheen = true;
    bool glassCaustics = true;
    bool glassSpecular = true;
    bool glassRefractionRim = true;
    bool accentGlow = true;
    float accentGlowIntensity = 0.80f;
    float accentGlowRadius = 32.0f;
    bool softShadow = true;
    float shadowSoftness = 0.70f;

    // Colors & Theming
    D2D1_COLOR_F pillBgColor = D2D1::ColorF(0.051f, 0.051f, 0.059f, 1.0f); // #0D0D0F
    D2D1_COLOR_F textPrimaryColor = D2D1::ColorF(0.969f, 0.969f, 0.969f, 1.0f); // #F7F7F7
    D2D1_COLOR_F textSecondaryColor = D2D1::ColorF(0.533f, 0.533f, 0.533f, 1.0f); // #888888
    AccentMode accentMode = AccentMode::Auto;
    D2D1_COLOR_F customAccent = D2D1::ColorF(0x4cc9f0);
    float tintOpacity = 0.72f;
    float pillOpacity = 0.96f;

    // Physics & Performance
    float animationSpeed = 1.0f;
    SpringStyle springStyle = SpringStyle::Bouncy;
    int targetFps = 60;
    bool lowPowerMode = false;

    // Modules & Smart Features
    bool media = true;
    bool notification = true;
    bool clipboard = true;
    bool battery = true;
    bool progress = true;
    bool volume = true;
    bool capsLock = true;
    bool device = true;
    bool gameOverlay = false;
    bool showMetricText = true;
    bool showMetricsInIdle = false;
    std::wstring weatherCity;
    bool weatherFahrenheit = false;
    float notificationDuration = 4.0f;
    float clipboardDuration = 2.5f;
    float volumeDuration = 1.8f;
    float capsLockDuration = 1.5f;
    float deviceDuration = 3.0f;

    // Fine Tuning & Advanced
    float splitGap = 12.0f;
    float hoverScalePercent = 1.02f;
    float nudgeOffsetPx = 8.0f;
    int waveformBarCount = 22;
    float waveformGapPx = 2.5f;
    float progressRingThickness = 2.8f;
    float paginationDotSize = 2.5f;
    float privacyDotSize = 3.8f;
    float topHighlightOpacity = 0.35f;
    float rimThickness = 0.9f;
    float shadowSpreadPx = 10.0f;
    float shadowYOffsetPx = 4.0f;
    float causticsSpeed = 1.3f;
    bool contentFadeOnResize = true;
    bool useDwmBlurBehind = false;
    int weatherUpdateMinutes = 10;
};

struct BitmapPixels {
    std::vector<uint8_t> bgra;
    UINT width = 0;
    UINT height = 0;
    uint64_t generation = 0;
    D2D1_COLOR_F sampledAccent = D2D1::ColorF(0x4cc9f0);
};

struct MediaSnapshot {
    bool available = false;
    bool playing = false;
    std::wstring title;
    std::wstring artist;
    std::wstring sourceAppUserModelId;
    std::wstring sourceName;
    std::wstring sourceBadge;
    BitmapPixels art;
    BitmapPixels sourceIcon;
    uint64_t artGeneration = 0;
    uint64_t sourceIconGeneration = 0;
    double artChangedAt = 0.0;
    int64_t positionTicks = 0;
    int64_t endTicks = 0;
    int64_t lastUpdatedTicks = 0;
};

struct ClipboardSnapshot {
    bool active = false;
    bool image = false;
    std::wstring text;
    std::wstring appName;
    BitmapPixels appIcon;
    double expiresAt = 0.0;
};

struct BatterySnapshot {
    bool active = false;
    bool low = false;
    bool charging = false;
    int percent = 100;
    DWORD secondsRemaining = BATTERY_LIFE_UNKNOWN;
    double expiresAt = 0.0;
};

struct ProgressSnapshot {
    bool active = false;
    int percent = 0;
};

struct NotificationSnapshot {
    bool active = false;
    std::wstring app;
    std::wstring title;
    std::wstring body;
    BitmapPixels icon;
    double expiresAt = 0.0;
};

struct VolumeSnapshot {
    bool active = false;
    int percent = 0;
    bool muted = false;
    std::wstring deviceName;
    double expiresAt = 0.0;
};

struct CapsLockSnapshot {
    bool active = false;
    bool capsOn = false;
    bool numOn = false;
    bool isNumEvent = false;
    double expiresAt = 0.0;
};

enum class DeviceEventType {
    Connected,
    Disconnected,
};

struct DeviceSnapshot {
    bool active = false;
    DeviceEventType eventType = DeviceEventType::Connected;
    std::wstring deviceName;
    bool isBluetoothLike = false;
    double expiresAt = 0.0;
};

struct SystemSnapshot {
    int volumePercent = 0;
    bool volumeMuted = false;
    int cpuPercent = 0;
    int memoryPercent = 0;
    int diskFreePercent = 0;
    int renderFps = 0;
    int gpuPercent = -1;
    bool charging = false;
    bool micActive = false;      // orange dot: microphone in use
    bool cameraActive = false;   // green dot: camera in use
    std::wstring foregroundTitle;
};

struct Activity {
    IslandKind kind = IslandKind::Idle;
    float width = 170.0f;
    float height = 36.0f;
};

struct WeatherSnapshot {
    bool hasData = false;
    float temperature = 0.0f;
    int weatherCode = 0;
    std::wstring city;
    std::wstring weatherDesc;
    std::wstring windSpeed;
    std::wstring windDir;
    std::wstring humidity;
    std::wstring feelsLike;
    double lastUpdated = 0.0;
};

struct SharedState {
    MediaSnapshot media;
    ClipboardSnapshot clipboard;
    NotificationSnapshot notification;
    VolumeSnapshot volume;
    CapsLockSnapshot capsLock;
    DeviceSnapshot device;
    BatterySnapshot battery;
    ProgressSnapshot progress;
    SystemSnapshot system;
    WeatherSnapshot weather;
    std::array<float, 64> waveform{};
    size_t waveformWrite = 0;
    bool muted = false;
};

// Global synchronization primitives
std::mutex g_stateMutex;
SharedState g_state;
std::mutex g_settingsMutex;
Settings g_settings;

std::atomic<bool> g_running = false;
std::atomic<bool> g_layoutDirty = true;
std::atomic<int> g_idleTab = 0;
std::atomic<int> g_pressedMediaButton = -1;
std::atomic<double> g_lastNudgeTime = 0.0;
std::atomic<uint64_t> g_artGenerationCounter = 1;

HWND g_hwnd = nullptr;
HANDLE g_stopEvent = nullptr;
HANDLE g_settingsChangedEvent = nullptr;
HANDLE g_renderThread = nullptr;
HANDLE g_mediaThread = nullptr;
HANDLE g_audioThread = nullptr;
HANDLE g_weatherThread = nullptr;
HANDLE g_notificationThread = nullptr;
HANDLE g_keyboardThread = nullptr;
DWORD g_keyboardThreadId = 0;
UINT g_shellHookMessage = 0;

HHOOK g_keyboardHook = nullptr;
FILETIME g_prevIdleTime{};
FILETIME g_prevKernelTime{};
FILETIME g_prevUserTime{};

constexpr GUID kSubTypeIeeeFloat = {
    0x00000003, 0x0000, 0x0010, {0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71}};

void UpdateSystemMetrics();
void UpdateBatteryMetrics();

// Mathematical & helper routines
inline float Clamp(float v, float lo, float hi) {
    return std::max(lo, std::min(hi, v));
}

inline int ClampInt(int v, int lo, int hi) {
    return std::max(lo, std::min(hi, v));
}

inline float Lerp(float a, float b, float t) {
    return a + (b - a) * t;
}

inline int Modulo(int a, int b) {
    if (b <= 0) return 0;
    return ((a % b) + b) % b;
}

double NowSeconds() {
    using namespace std::chrono;
    return duration_cast<duration<double>>(steady_clock::now().time_since_epoch()).count();
}

Settings GetSettingsSnapshot() {
    std::lock_guard lock(g_settingsMutex);
    return g_settings;
}

D2D1_COLOR_F ColorFromHex(std::wstring text, D2D1_COLOR_F fallback) {
    if (!text.empty() && text[0] == L'#') {
        text.erase(text.begin());
    }

    if (text.size() == 3) {
        wchar_t expanded[7] = {text[0], text[0], text[1], text[1], text[2], text[2], 0};
        text = expanded;
    }

    if (text.size() == 6) {
        wchar_t* end = nullptr;
        const unsigned long rgb = wcstoul(text.c_str(), &end, 16);
        if (!end || *end != L'\0') {
            return fallback;
        }

        return D2D1::ColorF(
            ((rgb >> 16) & 0xff) / 255.0f,
            ((rgb >> 8) & 0xff) / 255.0f,
            (rgb & 0xff) / 255.0f,
            1.0f);
    } else if (text.size() == 8) {
        wchar_t* end = nullptr;
        const unsigned long rgba = wcstoul(text.c_str(), &end, 16);
        if (!end || *end != L'\0') {
            return fallback;
        }

        return D2D1::ColorF(
            ((rgba >> 24) & 0xff) / 255.0f,
            ((rgba >> 16) & 0xff) / 255.0f,
            ((rgba >> 8) & 0xff) / 255.0f,
            (rgba & 0xff) / 255.0f);
    }

    return fallback;
}

float GetPrimaryMonitorDpiScale() {
    POINT pt = {0, 0};
    HMONITOR monitor = MonitorFromPoint(pt, MONITOR_DEFAULTTOPRIMARY);
    UINT dpiX = 96, dpiY = 96;
    using GetDpiForMonitor_t = HRESULT(WINAPI*)(HMONITOR, int, UINT*, UINT*);
    static auto pGetDpiForMonitor = reinterpret_cast<GetDpiForMonitor_t>(
        GetProcAddress(GetModuleHandleW(L"shcore.dll"), "GetDpiForMonitor"));
    if (pGetDpiForMonitor) {
        pGetDpiForMonitor(monitor, 0 /* MDT_EFFECTIVE_DPI */, &dpiX, &dpiY);
    }
    return dpiX / 96.0f;
}

float CalculateCornerRadius(float height, const Settings& settings) {
    switch (settings.cornerStyle) {
        case CornerStyle::Sharp:
            return 0.0f;
        case CornerStyle::ModernBox:
            return std::min(height * 0.5f, 8.0f * settings.sizeScale);
        case CornerStyle::Squircle:
            return std::min(height * 0.5f, 22.0f * settings.sizeScale);
        case CornerStyle::Custom:
            return std::min(height * 0.5f, std::max(0.0f, settings.customCornerRadius) * settings.sizeScale);
        case CornerStyle::Pill:
        default:
            return height * 0.5f;
    }
}

class SpringValue {
   public:
    void Reset(float value) {
        position_ = value;
        target_ = value;
        velocity_ = 0.0f;
    }

    void SetTarget(float target) {
        target_ = target;
    }

    float GetPosition() const {
        return position_;
    }

    float GetTarget() const {
        return target_;
    }

    bool IsSettled(float eps = 0.05f) const {
        return std::abs(target_ - position_) < eps && std::abs(velocity_) < eps;
    }

    void UpdateWith(float target, float stiffness, float damping, float dt) {
        target_ = target;
        dt = std::min(dt, 0.05f);
        const float force = -stiffness * (position_ - target_);
        const float dampingForce = -damping * velocity_;
        const float acceleration = force + dampingForce;
        velocity_ += acceleration * dt;
        position_ += velocity_ * dt;
    }

    void Update(float target, SpringStyle style, float speedMultiplier, float dt) {
        float stiffness = 320.0f;
        float damping = 22.0f;

        switch (style) {
            case SpringStyle::Smooth:
                stiffness = 240.0f;
                damping = 31.0f;
                break;
            case SpringStyle::Snappy:
                stiffness = 460.0f;
                damping = 34.0f;
                break;
            case SpringStyle::Stiff:
                stiffness = 380.0f;
                damping = 40.0f;
                break;
            case SpringStyle::Bouncy:
            default:
                stiffness = 320.0f;
                damping = 22.0f;
                break;
        }

        stiffness *= (speedMultiplier * speedMultiplier);
        damping *= speedMultiplier;

        UpdateWith(target, stiffness, damping, dt);
    }

   private:
    float position_ = 0.0f;
    float target_ = 0.0f;
    float velocity_ = 0.0f;
};

bool EqualsNoCase(std::wstring_view a, std::wstring_view b) {
    if (a.size() != b.size()) return false;
    return std::equal(a.begin(), a.end(), b.begin(), b.end(),
                      [](wchar_t ca, wchar_t cb) { return towlower(ca) == towlower(cb); });
}

std::wstring GetStringSettingCopy(PCWSTR name) {
    PCWSTR value = Wh_GetStringSetting(name);
    std::wstring result = value ? value : L"";
    Wh_FreeStringSetting(value);
    return result;
}

void LoadSettings() {
    Settings next;

    // Position
    const std::wstring position = GetStringSettingCopy(L"Appearance.Position");
    if (EqualsNoCase(position, L"top-left")) next.position = Position::TopLeft;
    else if (EqualsNoCase(position, L"top-right")) next.position = Position::TopRight;
    else if (EqualsNoCase(position, L"bottom-center")) next.position = Position::BottomCenter;
    else if (EqualsNoCase(position, L"bottom-left")) next.position = Position::BottomLeft;
    else if (EqualsNoCase(position, L"bottom-right")) next.position = Position::BottomRight;
    else if (EqualsNoCase(position, L"center")) next.position = Position::Center;
    else next.position = Position::TopCenter;

    // Monitor
    std::wstring mon = GetStringSettingCopy(L"Appearance.TargetMonitor");
    if (mon == L"primary" || mon.empty()) next.targetMonitor = 0;
    else if (mon == L"follow") next.targetMonitor = -1;
    else next.targetMonitor = _wtoi(mon.c_str());

    // Offsets & Margins
    next.offsetX = Wh_GetIntSetting(L"Appearance.OffsetX");
    next.offsetY = Wh_GetIntSetting(L"Appearance.OffsetY");
    const int marginSetting = Wh_GetIntSetting(L"Appearance.EdgeMargin");
    next.edgeMargin = marginSetting != 0 ? marginSetting : 8;

    // Size Scale
    const std::wstring scale = GetStringSettingCopy(L"Appearance.SizeScale");
    if (!scale.empty()) {
        wchar_t* end = nullptr;
        float parsedScale = wcstof(scale.c_str(), &end);
        if (end != scale.c_str() && parsedScale > 0.1f && parsedScale < 10.0f) {
            next.sizeScale = parsedScale;
        }
    }
    if (Wh_GetIntSetting(L"Appearance.AutoDpiScale") != 0) {
        next.sizeScale *= GetPrimaryMonitorDpiScale();
    }

    // Corner Style & Radius
    const std::wstring cornerStr = GetStringSettingCopy(L"Appearance.CornerStyle");
    if (EqualsNoCase(cornerStr, L"squircle")) next.cornerStyle = CornerStyle::Squircle;
    else if (EqualsNoCase(cornerStr, L"modern-box")) next.cornerStyle = CornerStyle::ModernBox;
    else if (EqualsNoCase(cornerStr, L"sharp")) next.cornerStyle = CornerStyle::Sharp;
    else if (EqualsNoCase(cornerStr, L"custom")) next.cornerStyle = CornerStyle::Custom;
    else next.cornerStyle = CornerStyle::Pill;
    
    const int customRad = Wh_GetIntSetting(L"Appearance.CustomCornerRadius");
    next.customCornerRadius = customRad > 0 ? static_cast<float>(customRad) : 18.0f;

    const int localCorner = Wh_GetIntValue(L"CornerStyleOverride", -1);
    if (localCorner >= 0 && localCorner <= 4) {
        next.cornerStyle = static_cast<CornerStyle>(localCorner);
    }

    // Dimensions
    const int colW = Wh_GetIntSetting(L"Appearance.CollapsedWidth");
    next.collapsedWidth = colW >= 60 ? static_cast<float>(colW) : 170.0f;
    const int colH = Wh_GetIntSetting(L"Appearance.CollapsedHeight");
    next.collapsedHeight = colH >= 20 ? static_cast<float>(colH) : 36.0f;
    const int expW = Wh_GetIntSetting(L"Appearance.ExpandedWidth");
    next.expandedWidth = expW >= 200 ? static_cast<float>(expW) : 380.0f;
    const int expH = Wh_GetIntSetting(L"Appearance.ExpandedHeight");
    next.expandedHeight = expH >= 80 ? static_cast<float>(expH) : 184.0f;

    // Auto-Hide & Interactions
    const std::wstring hideSec = GetStringSettingCopy(L"Appearance.AutoHideIdleSeconds");
    next.autoHideIdleSeconds = hideSec.empty() ? 0 : _wtoi(hideSec.c_str());
    next.unhideOnHover = Wh_GetIntSetting(L"Appearance.UnhideOnHover") != 0;
    next.alwaysOnTop = Wh_GetIntSetting(L"Appearance.AlwaysOnTop") != 0;
    const int localExpandOnHover = Wh_GetIntValue(L"ExpandOnHoverOverride", -1);
    next.expandOnHover = localExpandOnHover >= 0 ? (localExpandOnHover != 0) : (Wh_GetIntSetting(L"Appearance.ExpandOnHover") != 0);
    next.autoDpiScale = Wh_GetIntSetting(L"Appearance.AutoDpiScale") != 0;
    next.clickThroughIdle = Wh_GetIntSetting(L"Appearance.ClickThroughIdle") != 0;

    // Optics & Liquid Glass
    const int localLiquidGlass = Wh_GetIntValue(L"LiquidGlassOverride", -1);
    next.liquidGlass = localLiquidGlass >= 0 ? (localLiquidGlass != 0) : (Wh_GetIntSetting(L"Optics.LiquidGlass") != 0 || Wh_GetIntSetting(L"Themes.LiquidGlass") != 0);
    const int glassIntensitySetting = Wh_GetIntSetting(L"Optics.LiquidGlassIntensity");
    const int localGlassIntensity = Wh_GetIntValue(L"LiquidGlassIntensityOverride", -1);
    next.liquidGlassIntensity = Clamp((localGlassIntensity >= 0 ? localGlassIntensity : (glassIntensitySetting ? glassIntensitySetting : 80)) / 100.0f, 0.0f, 1.0f);
    
    next.glassSheen = Wh_GetIntSetting(L"Optics.GlassSheen") != 0;
    next.glassCaustics = Wh_GetIntSetting(L"Optics.GlassCaustics") != 0;
    next.glassSpecular = Wh_GetIntSetting(L"Optics.GlassSpecular") != 0;
    next.glassRefractionRim = Wh_GetIntSetting(L"Optics.GlassRefractionRim") != 0;

    const int localAccentGlow = Wh_GetIntValue(L"AccentGlowOverride", -1);
    next.accentGlow = localAccentGlow >= 0 ? (localAccentGlow != 0) : (Wh_GetIntSetting(L"Optics.AccentGlow") != 0 || Wh_GetIntSetting(L"Themes.AccentGlow") != 0);
    const int glowIntensitySetting = Wh_GetIntSetting(L"Optics.AccentGlowIntensity");
    const int glowRadiusOverride = Wh_GetIntValue(L"AccentGlowRadiusOverride", -1);
    next.accentGlowIntensity = Clamp((glowIntensitySetting ? glowIntensitySetting : 80) / 100.0f, 0.0f, 1.0f);
    const int glowRadSetting = glowRadiusOverride >= 5 ? glowRadiusOverride : Wh_GetIntSetting(L"Optics.AccentGlowRadius");
    next.accentGlowRadius = glowRadSetting >= 5 ? static_cast<float>(glowRadSetting) : 32.0f;

    next.softShadow = Wh_GetIntSetting(L"Optics.SoftShadow") != 0;
    const int shadowSoft = Wh_GetIntSetting(L"Optics.ShadowSoftness");
    next.shadowSoftness = Clamp((shadowSoft ? shadowSoft : 70) / 100.0f, 0.0f, 1.0f);

    // Accent Colors & Modes
    const std::wstring accentMode = GetStringSettingCopy(L"Themes.AccentColorMode");
    if (EqualsNoCase(accentMode, L"system")) next.accentMode = AccentMode::System;
    else if (EqualsNoCase(accentMode, L"custom")) next.accentMode = AccentMode::Custom;
    else next.accentMode = AccentMode::Auto;
    
    next.customAccent = ColorFromHex(GetStringSettingCopy(L"Themes.CustomAccentHex"), next.customAccent);

    // Base Colors & Opacities
    next.tintOpacity = Clamp((Wh_GetIntSetting(L"Themes.TintIntensity") ? Wh_GetIntSetting(L"Themes.TintIntensity") : 72) / 100.0f, 0.0f, 1.0f);
    const int settingOpacity = Wh_GetIntSetting(L"Themes.PillOpacity");
    const int localOpacity = Wh_GetIntValue(L"PillOpacityOverride", -1);
    next.pillOpacity = Clamp((localOpacity >= 0 ? localOpacity : (settingOpacity ? settingOpacity : 96)) / 100.0f, 0.10f, 1.0f);

    // Curated color theme presets
    struct ThemeColors { const wchar_t* bg; const wchar_t* fg; const wchar_t* sec; };
    static constexpr ThemeColors kThemes[] = {
        {L"#0D0D0F", L"#F7F7F7", L"#888888"},  // 0: OLED Black (default)
        {L"#1C1C1E", L"#FFFFFF", L"#999999"},  // 1: Dark Gray
        {L"#050D1A", L"#E8F0FF", L"#7090BB"},  // 2: Midnight Blue
        {L"#0E0014", L"#F0E8FF", L"#9060BB"},  // 3: Deep Purple
        {L"#1F1F1F", L"#FFFFFF", L"#A0A0A0"},  // 4: Fluent Design
        {L"#080808", L"#FFFFFF", L"#8E8E93"},  // 5: Liquid Black
        {L"#24272C", L"#FFFFFF", L"#A2ACB8"},  // 6: Liquid Silver
        {L"#050518", L"#E0E6FF", L"#7B8AB8"},  // 7: Liquid Night
        {L"#040F18", L"#E0FFF8", L"#62B8A8"},  // 8: Liquid Aurora
        {L"#000000", L"#FFFFFF", L"#CCCCCC"},  // 9: Pure Glass / Crystal Clear
    };
    const int theme = Wh_GetIntValue(L"ColorTheme", -1);
    if (theme >= 0 && theme < static_cast<int>(ARRAYSIZE(kThemes))) {
        next.pillBgColor = ColorFromHex(kThemes[theme].bg, D2D1::ColorF(0.051f, 0.051f, 0.059f, 1.0f));
        next.textPrimaryColor = ColorFromHex(kThemes[theme].fg, D2D1::ColorF(0.969f, 0.969f, 0.969f, 1.0f));
        next.textSecondaryColor = ColorFromHex(kThemes[theme].sec, D2D1::ColorF(0.533f, 0.533f, 0.533f, 1.0f));
    } else {
        next.pillBgColor = ColorFromHex(GetStringSettingCopy(L"Themes.PillBgColor"), D2D1::ColorF(0.051f, 0.051f, 0.059f, 1.0f));
        next.textPrimaryColor = ColorFromHex(GetStringSettingCopy(L"Themes.TextPrimaryColor"), D2D1::ColorF(0.969f, 0.969f, 0.969f, 1.0f));
        next.textSecondaryColor = ColorFromHex(GetStringSettingCopy(L"Themes.TextSecondaryColor"), D2D1::ColorF(0.533f, 0.533f, 0.533f, 1.0f));
    }

    // Animation & Physics
    const std::wstring speed = GetStringSettingCopy(L"Performance.AnimationSpeed");
    if (EqualsNoCase(speed, L"slow")) next.animationSpeed = 0.65f;
    else if (EqualsNoCase(speed, L"fast")) next.animationSpeed = 1.35f;
    else if (EqualsNoCase(speed, L"instant")) next.animationSpeed = 5.0f;
    else next.animationSpeed = 1.0f;

    const std::wstring springStr = GetStringSettingCopy(L"Performance.SpringStyle");
    if (EqualsNoCase(springStr, L"smooth")) next.springStyle = SpringStyle::Smooth;
    else if (EqualsNoCase(springStr, L"snappy")) next.springStyle = SpringStyle::Snappy;
    else if (EqualsNoCase(springStr, L"stiff")) next.springStyle = SpringStyle::Stiff;
    else next.springStyle = SpringStyle::Bouncy;

    const std::wstring fpsStr = GetStringSettingCopy(L"Performance.FrameRateTarget");
    next.targetFps = fpsStr.empty() ? 60 : _wtoi(fpsStr.c_str());
    if (next.targetFps < 15 || next.targetFps > 360) next.targetFps = 60;
    next.lowPowerMode = Wh_GetIntSetting(L"Performance.LowPowerMode") != 0;

    // Modules
    next.media = Wh_GetIntSetting(L"Modules.Media") != 0;
    next.notification = Wh_GetIntSetting(L"Modules.Notification") != 0;
    next.clipboard = Wh_GetIntSetting(L"Modules.Clipboard") != 0;
    next.battery = Wh_GetIntSetting(L"Modules.Battery") != 0;
    next.progress = Wh_GetIntSetting(L"Modules.Progress") != 0;
    next.volume = Wh_GetIntSetting(L"Modules.Volume") != 0;
    next.capsLock = Wh_GetIntSetting(L"Modules.CapsLock") != 0;
    next.device = Wh_GetIntSetting(L"Modules.Device") != 0;
    next.gameOverlay = Wh_GetIntSetting(L"Modules.GameOverlay") != 0;
    next.showMetricText = Wh_GetIntSetting(L"Modules.ShowMetricText") != 0;
    const int localShowMetricsInIdle = Wh_GetIntValue(L"ShowMetricsInIdleOverride", -1);
    next.showMetricsInIdle = localShowMetricsInIdle >= 0 ? (localShowMetricsInIdle != 0) : (Wh_GetIntSetting(L"Modules.ShowMetricsInIdle") != 0);
    next.weatherCity = GetStringSettingCopy(L"Modules.WeatherCity");
    next.weatherFahrenheit = Wh_GetIntSetting(L"Modules.WeatherFahrenheit") != 0;

    const std::wstring notifDur = GetStringSettingCopy(L"Modules.NotificationDuration");
    if (!notifDur.empty()) {
        float d = wcstof(notifDur.c_str(), nullptr);
        if (d > 0.5f && d < 30.0f) next.notificationDuration = d;
    }
    const std::wstring clipDur = GetStringSettingCopy(L"Modules.ClipboardDuration");
    if (!clipDur.empty()) {
        float d = wcstof(clipDur.c_str(), nullptr);
        if (d > 0.5f && d < 30.0f) next.clipboardDuration = d;
    }
    const std::wstring volDur = GetStringSettingCopy(L"Modules.VolumeDuration");
    if (!volDur.empty()) {
        float d = wcstof(volDur.c_str(), nullptr);
        if (d > 0.5f && d < 30.0f) next.volumeDuration = d;
    }
    const std::wstring capsDur = GetStringSettingCopy(L"Modules.CapsLockDuration");
    if (!capsDur.empty()) {
        float d = wcstof(capsDur.c_str(), nullptr);
        if (d > 0.5f && d < 30.0f) next.capsLockDuration = d;
    }
    const std::wstring devDur = GetStringSettingCopy(L"Modules.DeviceDuration");
    if (!devDur.empty()) {
        float d = wcstof(devDur.c_str(), nullptr);
        if (d > 0.5f && d < 30.0f) next.deviceDuration = d;
    }

    // Fine Tuning & Advanced
    {
        int v = Wh_GetIntSetting(L"FineTuning.SplitGap");
        next.splitGap = Clamp(v ? static_cast<float>(v) : 12.0f, 4.0f, 32.0f);
        int hs = Wh_GetIntSetting(L"FineTuning.HoverScalePercent");
        next.hoverScalePercent = Clamp((hs ? hs : 102) / 100.0f, 1.0f, 1.15f);
        int nudge = Wh_GetIntSetting(L"FineTuning.NudgeOffsetPx");
        next.nudgeOffsetPx = Clamp(nudge >= 0 ? static_cast<float>(nudge) : 8.0f, 0.0f, 20.0f);
        int wbc = Wh_GetIntSetting(L"FineTuning.WaveformBarCount");
        next.waveformBarCount = ClampInt(wbc ? wbc : 22, 8, 32);
        std::wstring wGap = GetStringSettingCopy(L"FineTuning.WaveformGapPx");
        if (!wGap.empty()) {
            float f = wcstof(wGap.c_str(), nullptr);
            if (f >= 1.0f && f <= 6.0f) next.waveformGapPx = f;
        }
        std::wstring prt = GetStringSettingCopy(L"FineTuning.ProgressRingThickness");
        if (!prt.empty()) {
            float f = wcstof(prt.c_str(), nullptr);
            if (f >= 1.0f && f <= 6.0f) next.progressRingThickness = f;
        }
        std::wstring pds = GetStringSettingCopy(L"FineTuning.PaginationDotSize");
        if (!pds.empty()) {
            float f = wcstof(pds.c_str(), nullptr);
            if (f >= 1.0f && f <= 6.0f) next.paginationDotSize = f;
        }
        std::wstring priv = GetStringSettingCopy(L"FineTuning.PrivacyDotSize");
        if (!priv.empty()) {
            float f = wcstof(priv.c_str(), nullptr);
            if (f >= 2.0f && f <= 8.0f) next.privacyDotSize = f;
        }
        int tho = Wh_GetIntSetting(L"FineTuning.TopHighlightOpacity");
        next.topHighlightOpacity = Clamp((tho ? tho : 35) / 100.0f, 0.0f, 1.0f);
        std::wstring rimT = GetStringSettingCopy(L"FineTuning.RimThickness");
        if (!rimT.empty()) {
            float f = wcstof(rimT.c_str(), nullptr);
            if (f >= 0.2f && f <= 3.0f) next.rimThickness = f;
        }
        int ss = Wh_GetIntSetting(L"FineTuning.ShadowSpreadPx");
        next.shadowSpreadPx = Clamp(ss >= 0 ? static_cast<float>(ss) : 10.0f, 0.0f, 24.0f);
        int sy = Wh_GetIntSetting(L"FineTuning.ShadowYOffsetPx");
        next.shadowYOffsetPx = Clamp(sy >= 0 ? static_cast<float>(sy) : 4.0f, 0.0f, 12.0f);
        std::wstring cs = GetStringSettingCopy(L"FineTuning.CausticsSpeed");
        if (!cs.empty()) {
            float f = wcstof(cs.c_str(), nullptr);
            if (f >= 0.0f && f <= 5.0f) next.causticsSpeed = f;
        }
        {
            std::wstring cf = GetStringSettingCopy(L"FineTuning.ContentFadeOnResize");
            if (cf.empty()) next.contentFadeOnResize = true;
            else next.contentFadeOnResize = Wh_GetIntSetting(L"FineTuning.ContentFadeOnResize") != 0;
        }
        next.useDwmBlurBehind = Wh_GetIntSetting(L"FineTuning.UseDwmBlurBehind") != 0;
        int wum = Wh_GetIntSetting(L"FineTuning.WeatherUpdateMinutes");
        next.weatherUpdateMinutes = ClampInt(wum ? wum : 10, 5, 60);
    }

    bool cityChanged = false;
    {
        std::lock_guard lock(g_settingsMutex);
        cityChanged = (next.weatherCity != g_settings.weatherCity);
        g_settings = next;
    }
    g_layoutDirty = true;
    if (cityChanged && g_settingsChangedEvent) {
        SetEvent(g_settingsChangedEvent);
    }
}

void EnableBlurBehind(HWND hwnd) {
    Settings s = GetSettingsSnapshot();
    DWM_BLURBEHIND blur = {};
    blur.dwFlags = DWM_BB_ENABLE;
    blur.fEnable = s.useDwmBlurBehind ? TRUE : FALSE;
    if (s.useDwmBlurBehind) {
        blur.hRgnBlur = nullptr;
        blur.dwFlags |= DWM_BB_BLURREGION;
    }
    DwmEnableBlurBehindWindow(hwnd, &blur);
}

struct MonitorEnumData {
    std::vector<HMONITOR> monitors;
};

BOOL CALLBACK MonitorEnumProc(HMONITOR hMonitor, HDC, LPRECT, LPARAM dwData) {
    auto* data = reinterpret_cast<MonitorEnumData*>(dwData);
    data->monitors.push_back(hMonitor);
    return TRUE;
}

RECT GetAnchorWorkRect() {
    HMONITOR selectedMonitor = nullptr;
    Settings settings = GetSettingsSnapshot();

    if (settings.targetMonitor == -1) {
        POINT pt = {0, 0};
        GetCursorPos(&pt);
        selectedMonitor = MonitorFromPoint(pt, MONITOR_DEFAULTTONEAREST);
    } else if (settings.targetMonitor > 0) {
        MonitorEnumData data;
        EnumDisplayMonitors(nullptr, nullptr, MonitorEnumProc, reinterpret_cast<LPARAM>(&data));
        
        int index = settings.targetMonitor - 1;
        if (index >= 0 && index < static_cast<int>(data.monitors.size())) {
            selectedMonitor = data.monitors[index];
        }
    }

    if (!selectedMonitor) {
        POINT pt = {0, 0};
        selectedMonitor = MonitorFromPoint(pt, MONITOR_DEFAULTTOPRIMARY);
    }

    MONITORINFO mi = {};
    mi.cbSize = sizeof(mi);
    GetMonitorInfoW(selectedMonitor, &mi);
    return mi.rcWork;
}

void PositionOverlayWindow(HWND hwnd, int width, int height) {
    Settings settings = GetSettingsSnapshot();
    RECT work = GetAnchorWorkRect();
    const int margin = settings.edgeMargin;
    int x = work.left + (work.right - work.left - width) / 2;
    int y = work.top + margin;

    switch (settings.position) {
        case Position::TopLeft:
            x = work.left + margin;
            y = work.top + margin;
            break;
        case Position::TopRight:
            x = work.right - width - margin;
            y = work.top + margin;
            break;
        case Position::BottomCenter:
            x = work.left + (work.right - work.left - width) / 2;
            y = work.bottom - height - margin;
            break;
        case Position::BottomLeft:
            x = work.left + margin;
            y = work.bottom - height - margin;
            break;
        case Position::BottomRight:
            x = work.right - width - margin;
            y = work.bottom - height - margin;
            break;
        case Position::Center:
            x = work.left + (work.right - work.left - width) / 2;
            y = work.top + (work.bottom - work.top - height) / 2;
            break;
        case Position::TopCenter:
        default:
            x = work.left + (work.right - work.left - width) / 2;
            y = work.top + margin;
            break;
    }

    x += settings.offsetX;
    y += settings.offsetY;

    static int lastX = INT_MIN, lastY = INT_MIN, lastW = INT_MIN, lastH = INT_MIN;
    static bool lastTopMost = false;
    bool topMost = settings.alwaysOnTop;
    if (x == lastX && y == lastY && width == lastW && height == lastH && topMost == lastTopMost) return;
    lastX = x; lastY = y; lastW = width; lastH = height; lastTopMost = topMost;

    SetWindowPos(hwnd, topMost ? HWND_TOPMOST : HWND_NOTOPMOST,
                 x, y, width, height,
                 SWP_NOACTIVATE | SWP_NOREDRAW | SWP_NOSENDCHANGING);
}

// Activity Prioritization
std::vector<IslandKind> ChooseActivities(const SharedState& state, const Settings& settings,
                                         double now) {
    std::vector<IslandKind> chosen;

    if (settings.device && state.device.active && state.device.expiresAt > now) {
        chosen.push_back(IslandKind::Device);
        return chosen;
    }

    if (settings.capsLock && state.capsLock.active && state.capsLock.expiresAt > now) {
        chosen.push_back(IslandKind::CapsLock);
        return chosen;
    }

    if (settings.volume && state.volume.active && state.volume.expiresAt > now) {
        chosen.push_back(IslandKind::Volume);
        return chosen;
    }

    if (settings.battery && state.battery.active && state.battery.expiresAt > now) {
        chosen.push_back(IslandKind::BatteryLow);
        return chosen;
    }

    if (settings.notification && state.notification.active && state.notification.expiresAt > now) {
        chosen.push_back(IslandKind::Notification);
        return chosen;
    }

    if (settings.clipboard && state.clipboard.active && state.clipboard.expiresAt > now) {
        chosen.push_back(IslandKind::Clipboard);
        return chosen;
    }

    if (settings.media && state.media.available) {
        chosen.push_back(IslandKind::Media);
    }

    if (settings.progress && state.progress.active) {
        chosen.push_back(IslandKind::Progress);
    }

    if (chosen.empty()) {
        chosen.push_back(IslandKind::Idle);
    }

    return chosen;
}

bool DecodeImageBytesToPixels(const std::vector<uint8_t>& bytes, BitmapPixels* outPixels) {
    if (!outPixels || bytes.empty()) {
        return false;
    }

    ComPtr<IWICImagingFactory> factory;
    HRESULT hr = CoCreateInstance(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER,
                                  IID_PPV_ARGS(&factory));
    if (FAILED(hr)) return false;

    HGLOBAL mem = GlobalAlloc(GMEM_MOVEABLE, bytes.size());
    if (!mem) return false;

    void* locked = GlobalLock(mem);
    memcpy(locked, bytes.data(), bytes.size());
    GlobalUnlock(mem);

    ComPtr<IStream> stream;
    hr = CreateStreamOnHGlobal(mem, TRUE, &stream);
    if (FAILED(hr)) {
        GlobalFree(mem);
        return false;
    }

    ComPtr<IWICBitmapDecoder> decoder;
    hr = factory->CreateDecoderFromStream(stream.Get(), nullptr, WICDecodeMetadataCacheOnLoad, &decoder);
    if (FAILED(hr)) return false;

    ComPtr<IWICBitmapFrameDecode> frame;
    hr = decoder->GetFrame(0, &frame);
    if (FAILED(hr)) return false;

    ComPtr<IWICFormatConverter> converter;
    hr = factory->CreateFormatConverter(&converter);
    if (FAILED(hr)) return false;

    hr = converter->Initialize(frame.Get(), GUID_WICPixelFormat32bppPBGRA,
                               WICBitmapDitherTypeNone, nullptr, 0.0,
                               WICBitmapPaletteTypeCustom);
    if (FAILED(hr)) return false;

    UINT width = 0, height = 0;
    converter->GetSize(&width, &height);
    if (!width || !height || width > 2048 || height > 2048) return false;

    BitmapPixels pixels;
    pixels.width = width;
    pixels.height = height;
    pixels.bgra.resize(static_cast<size_t>(width) * height * 4);

    hr = converter->CopyPixels(nullptr, width * 4,
                               static_cast<UINT>(pixels.bgra.size()),
                               pixels.bgra.data());
    if (FAILED(hr)) return false;

    struct Bucket {
        uint32_t count = 0;
        uint32_t r = 0, g = 0, b = 0;
    };

    std::array<Bucket, 16 * 16 * 16> buckets{};
    for (size_t i = 0; i + 3 < pixels.bgra.size(); i += 4) {
        const uint8_t alpha = pixels.bgra[i + 3];
        const uint8_t blue = pixels.bgra[i + 0];
        const uint8_t green = pixels.bgra[i + 1];
        const uint8_t red = pixels.bgra[i + 2];
        if (alpha < 32) continue;

        const int maxc = std::max({red, green, blue});
        const int minc = std::min({red, green, blue});
        const int luminance = (54 * red + 183 * green + 19 * blue) / 256;
        const int saturation = maxc - minc;
        if (luminance < 28 || luminance > 232 || saturation < 24) continue;

        const size_t bucketIndex = ((red >> 4) << 8) | ((green >> 4) << 4) | (blue >> 4);
        Bucket& bucket = buckets[bucketIndex];
        const uint32_t weight = 1 + static_cast<uint32_t>(saturation / 48);
        bucket.count += weight;
        bucket.r += red * weight;
        bucket.g += green * weight;
        bucket.b += blue * weight;
    }

    const Bucket* best = nullptr;
    for (const Bucket& bucket : buckets) {
        if (!best || bucket.count > best->count) {
            best = &bucket;
        }
    }

    if (best && best->count > 0) {
        pixels.sampledAccent = D2D1::ColorF(
            Clamp((best->r / static_cast<float>(best->count)) / 255.0f, 0.14f, 1.0f),
            Clamp((best->g / static_cast<float>(best->count)) / 255.0f, 0.14f, 1.0f),
            Clamp((best->b / static_cast<float>(best->count)) / 255.0f, 0.14f, 1.0f),
            1.0f);
    }

    pixels.generation = ++g_artGenerationCounter;
    *outPixels = std::move(pixels);
    return true;
}

bool IconToPixels(HICON icon, UINT size, BitmapPixels* outPixels) {
    if (!icon || !outPixels || !size) return false;

    HDC screen = GetDC(nullptr);
    HDC dc = CreateCompatibleDC(screen);
    ReleaseDC(nullptr, screen);
    if (!dc) return false;

    BITMAPINFO bi = {};
    bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bi.bmiHeader.biWidth = static_cast<LONG>(size);
    bi.bmiHeader.biHeight = -static_cast<LONG>(size);
    bi.bmiHeader.biPlanes = 1;
    bi.bmiHeader.biBitCount = 32;
    bi.bmiHeader.biCompression = BI_RGB;

    void* bits = nullptr;
    HBITMAP bitmap = CreateDIBSection(dc, &bi, DIB_RGB_COLORS, &bits, nullptr, 0);
    if (!bitmap) {
        DeleteDC(dc);
        return false;
    }

    HGDIOBJ old = SelectObject(dc, bitmap);
    RECT fill = {0, 0, static_cast<LONG>(size), static_cast<LONG>(size)};
    FillRect(dc, &fill, reinterpret_cast<HBRUSH>(GetStockObject(NULL_BRUSH)));
    ZeroMemory(bits, static_cast<size_t>(size) * size * 4);
    DrawIconEx(dc, 0, 0, icon, size, size, 0, nullptr, DI_NORMAL);

    BitmapPixels pixels;
    pixels.width = size;
    pixels.height = size;
    pixels.bgra.resize(static_cast<size_t>(size) * size * 4);
    memcpy(pixels.bgra.data(), bits, pixels.bgra.size());

    bool hasAlpha = false;
    for (size_t i = 3; i < pixels.bgra.size(); i += 4) {
        if (pixels.bgra[i] != 0) {
            hasAlpha = true;
            break;
        }
    }
    if (!hasAlpha) {
        for (size_t i = 0; i + 3 < pixels.bgra.size(); i += 4) {
            const bool black = pixels.bgra[i] < 4 && pixels.bgra[i + 1] < 4 && pixels.bgra[i + 2] < 4;
            pixels.bgra[i + 3] = black ? 0 : 255;
        }
    } else {
        for (size_t i = 0; i + 3 < pixels.bgra.size(); i += 4) {
            const uint8_t a = pixels.bgra[i + 3];
            if (a < 255 && a > 0) {
                pixels.bgra[i + 0] = static_cast<uint8_t>(pixels.bgra[i + 0] * a / 255);
                pixels.bgra[i + 1] = static_cast<uint8_t>(pixels.bgra[i + 1] * a / 255);
                pixels.bgra[i + 2] = static_cast<uint8_t>(pixels.bgra[i + 2] * a / 255);
            }
        }
    }

    pixels.generation = ++g_artGenerationCounter;
    *outPixels = std::move(pixels);

    SelectObject(dc, old);
    DeleteObject(bitmap);
    DeleteDC(dc);
    return true;
}

bool ProcessImageNameForPid(DWORD pid, std::wstring* imageName) {
    if (!pid || !imageName) return false;

    HANDLE process = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
    if (!process) return false;

    wchar_t path[MAX_PATH] = {};
    DWORD size = ARRAYSIZE(path);
    const bool ok = QueryFullProcessImageNameW(process, 0, path, &size) != FALSE;
    CloseHandle(process);
    if (ok) *imageName = path;
    return ok;
}

HICON CopyWindowIcon(HWND hwnd, WPARAM iconType) {
    DWORD_PTR result = 0;
    SendMessageTimeoutW(hwnd, WM_GETICON, iconType, 0,
                        SMTO_ABORTIFHUNG | SMTO_BLOCK, 80, &result);
    return result ? CopyIcon(reinterpret_cast<HICON>(result)) : nullptr;
}

HICON getProcessIcon(DWORD pid) {
    std::wstring path;
    if (ProcessImageNameForPid(pid, &path) && !path.empty()) {
        HICON hIcon = nullptr;
        UINT iconId = 0;
        using PrivateExtractIconsW_t = UINT(WINAPI*)(LPCWSTR, int, int, int, HICON*, UINT*, UINT, UINT);
        static auto pPrivateExtractIconsW = reinterpret_cast<PrivateExtractIconsW_t>(
            GetProcAddress(GetModuleHandleW(L"user32.dll"), "PrivateExtractIconsW"));
        if (pPrivateExtractIconsW && pPrivateExtractIconsW(path.c_str(), 0, 64, 64, &hIcon, &iconId, 1, 0) == 1 && hIcon) {
            return hIcon;
        }

        SHFILEINFOW sfi = {};
        if (SHGetFileInfoW(path.c_str(), 0, &sfi, sizeof(sfi), SHGFI_ICON | SHGFI_LARGEICON)) {
            return sfi.hIcon;
        }

        HICON large = nullptr;
        HICON small = nullptr;
        if (ExtractIconExW(path.c_str(), 0, &large, &small, 1) > 0) {
            if (small) DestroyIcon(small);
            if (large) return large;
        }
    }

    return CopyIcon(LoadIconW(nullptr, IDI_APPLICATION));
}

HICON getWindowIcon(HWND hwnd) {
    if (!hwnd) return CopyIcon(LoadIconW(nullptr, IDI_APPLICATION));

    if (HICON icon = CopyWindowIcon(hwnd, ICON_BIG)) return icon;
    if (HICON icon = CopyWindowIcon(hwnd, ICON_SMALL)) return icon;

    if (auto icon = reinterpret_cast<HICON>(GetClassLongPtrW(hwnd, GCLP_HICON))) return CopyIcon(icon);
    if (auto icon = reinterpret_cast<HICON>(GetClassLongPtrW(hwnd, GCLP_HICONSM))) return CopyIcon(icon);

    DWORD pid = 0;
    GetWindowThreadProcessId(hwnd, &pid);
    return getProcessIcon(pid);
}

std::wstring ToLowerCopy(std::wstring value) {
    std::transform(value.begin(), value.end(), value.begin(),
                   [](wchar_t ch) { return static_cast<wchar_t>(towlower(ch)); });
    return value;
}

std::wstring BaseNameFromPath(std::wstring path) {
    const size_t slash = path.find_last_of(L"\\/");
    if (slash != std::wstring::npos) path.erase(0, slash + 1);
    const size_t dot = path.find_last_of(L'.');
    if (dot != std::wstring::npos) path.erase(dot);
    return path;
}

std::wstring FriendlyMediaSourceName(const std::wstring& aumid) {
    if (aumid.empty()) return L"Now Playing";
    std::wstring lower = ToLowerCopy(aumid);

    if (lower.find(L"spotify") != std::wstring::npos) return L"Spotify";
    if (lower.find(L"applemusic") != std::wstring::npos || lower.find(L"apple music") != std::wstring::npos) return L"Apple Music";
    if (lower.find(L"chrome") != std::wstring::npos) return L"Google Chrome";
    if (lower.find(L"msedge") != std::wstring::npos || lower.find(L"edge") != std::wstring::npos) return L"Microsoft Edge";
    if (lower.find(L"firefox") != std::wstring::npos) return L"Mozilla Firefox";
    if (lower.find(L"brave") != std::wstring::npos) return L"Brave";
    if (lower.find(L"opera") != std::wstring::npos) return L"Opera";
    if (lower.find(L"tidal") != std::wstring::npos) return L"TIDAL";
    if (lower.find(L"deezer") != std::wstring::npos) return L"Deezer";
    if (lower.find(L"vlc") != std::wstring::npos) return L"VLC Media Player";
    if (lower.find(L"foobar") != std::wstring::npos) return L"foobar2000";
    if (lower.find(L"aimp") != std::wstring::npos) return L"AIMP";
    if (lower.find(L"wmplayer") != std::wstring::npos || lower.find(L"zune") != std::wstring::npos) return L"Windows Media Player";

    return BaseNameFromPath(aumid);
}

std::wstring MediaSourceBadge(const std::wstring& friendlyName) {
    std::wstring lower = ToLowerCopy(friendlyName);
    if (lower == L"spotify") return L"\u25b6 Spotify";
    if (lower == L"apple music") return L"\u266b Apple Music";
    if (lower == L"tidal") return L"\u25c8 TIDAL";
    if (lower == L"deezer") return L"\u2261 Deezer";
    if (lower == L"google chrome" || lower == L"microsoft edge" || lower == L"mozilla firefox" || lower == L"brave") return L"\U0001f310 Web";
    return L"\u25b6 " + friendlyName;
}

[[maybe_unused]] bool IsBrowserMediaSource(const std::wstring& aumid) {
    const std::wstring lower = ToLowerCopy(aumid);
    return lower.find(L"chrome") != std::wstring::npos ||
           lower.find(L"msedge") != std::wstring::npos ||
           lower.find(L"edge") != std::wstring::npos ||
           lower.find(L"firefox") != std::wstring::npos ||
           lower.find(L"brave") != std::wstring::npos ||
           lower.find(L"opera") != std::wstring::npos;
}

BitmapPixels GetWindowIconPixels(HWND hwnd, UINT size = 64) {
    BitmapPixels pixels;
    HICON icon = getWindowIcon(hwnd);
    if (icon) {
        IconToPixels(icon, size, &pixels);
        DestroyIcon(icon);
    }
    return pixels;
}

[[maybe_unused]] BitmapPixels GetProcessIconPixels(DWORD pid, UINT size = 64) {
    BitmapPixels pixels;
    HICON icon = getProcessIcon(pid);
    if (icon) {
        IconToPixels(icon, size, &pixels);
        DestroyIcon(icon);
    }
    return pixels;
}

struct AppIconSearchData {
    std::wstring targetName;
    HWND bestHwnd = nullptr;
};

BOOL CALLBACK FindAppIconWindowProc(HWND hwnd, LPARAM lParam) {
    if (!IsWindowVisible(hwnd)) return TRUE;
    auto* data = reinterpret_cast<AppIconSearchData*>(lParam);

    DWORD pid = 0;
    GetWindowThreadProcessId(hwnd, &pid);
    std::wstring path;
    if (ProcessImageNameForPid(pid, &path)) {
        std::wstring base = ToLowerCopy(BaseNameFromPath(path));
        std::wstring target = ToLowerCopy(data->targetName);
        if (base.find(target) != std::wstring::npos || target.find(base) != std::wstring::npos) {
            data->bestHwnd = hwnd;
            return FALSE;
        }
    }
    return TRUE;
}

BitmapPixels FindAppIconByName(const std::wstring& appName, UINT size = 64) {
    BitmapPixels pixels;
    if (appName.empty()) return pixels;

    AppIconSearchData data;
    data.targetName = appName;
    EnumWindows(FindAppIconWindowProc, reinterpret_cast<LPARAM>(&data));

    if (data.bestHwnd) {
        pixels = GetWindowIconPixels(data.bestHwnd, size);
    }
    return pixels;
}

BitmapPixels FindMediaSourceIcon(const std::wstring& aumid, UINT size = 64) {
    BitmapPixels pixels;
    if (aumid.empty()) return pixels;

    std::wstring exeName = aumid;
    const size_t bang = exeName.find(L'!');
    if (bang != std::wstring::npos) exeName.erase(bang);

    pixels = FindAppIconByName(BaseNameFromPath(exeName), size);
    return pixels;
}

std::vector<uint8_t> ReadWinRtStreamBytes(
    const winrt::Windows::Storage::Streams::IRandomAccessStreamReference& reference) {
    std::vector<uint8_t> bytes;
    if (!reference) return bytes;

    try {
        auto stream = reference.OpenReadAsync().get();
        if (!stream) return bytes;

        const uint64_t size64 = stream.Size();
        if (size64 == 0 || size64 > 8 * 1024 * 1024) return bytes;

        const uint32_t size = static_cast<uint32_t>(size64);
        winrt::Windows::Storage::Streams::DataReader reader(stream.GetInputStreamAt(0));
        reader.LoadAsync(size).get();
        bytes.resize(size);
        reader.ReadBytes(winrt::array_view<uint8_t>(bytes.data(), bytes.data() + bytes.size()));
    } catch (...) {}
    return bytes;
}

void TriggerNudge() {
    const double now = NowSeconds();
    const double previous = g_lastNudgeTime.load();
    if (now - previous < 0.45) return;
    g_lastNudgeTime = now;
    HWND hwnd = g_hwnd;
    if (hwnd) PostMessageW(hwnd, WM_APP_NEW_EVENT, 0, 0);
}

float SampleAudioAmplitude(BYTE* data, UINT32 frames, WAVEFORMATEX* format) {
    if (!data || !frames || !format || !format->nChannels) return 0.0f;

    double sum = 0.0;
    size_t samples = static_cast<size_t>(frames) * format->nChannels;

    if (format->wFormatTag == WAVE_FORMAT_IEEE_FLOAT ||
        (format->wFormatTag == WAVE_FORMAT_EXTENSIBLE &&
         format->cbSize >= sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX) &&
         IsEqualGUID(reinterpret_cast<WAVEFORMATEXTENSIBLE*>(format)->SubFormat, kSubTypeIeeeFloat))) {
        auto* f = reinterpret_cast<float*>(data);
        for (size_t i = 0; i < samples; ++i) sum += f[i] * f[i];
    } else if (format->wBitsPerSample == 16) {
        auto* s = reinterpret_cast<int16_t*>(data);
        for (size_t i = 0; i < samples; ++i) {
            float norm = s[i] / 32768.0f;
            sum += norm * norm;
        }
    } else {
        return 0.0f;
    }

    return static_cast<float>(std::sqrt(sum / samples));
}

void PushWaveformSample(float amplitude) {
    std::lock_guard lock(g_stateMutex);
    g_state.waveform[g_state.waveformWrite] = amplitude;
    g_state.waveformWrite = (g_state.waveformWrite + 1) % g_state.waveform.size();
}

void PushAudioChunks(BYTE* data, UINT32 frames, WAVEFORMATEX* format) {
    if (!data || !frames || !format) return;
    const UINT32 chunkSize = 480; // ~10ms chunks
    for (UINT32 offset = 0; offset < frames; offset += chunkSize) {
        UINT32 count = std::min(chunkSize, frames - offset);
        BYTE* chunkData = data + offset * format->nBlockAlign;
        float amp = SampleAudioAmplitude(chunkData, count, format);
        PushWaveformSample(amp);
    }
}

// PDH GPU queries
static PDH_HQUERY g_gpuQuery = NULL;
static PDH_HCOUNTER g_gpuCounter = NULL;

static void InitGpuQuery() {
    if (g_gpuQuery == NULL) {
        if (PdhOpenQueryW(NULL, 0, &g_gpuQuery) == ERROR_SUCCESS) {
            PdhAddEnglishCounterW(g_gpuQuery, L"\\GPU Engine(*)\\Utilization Percentage", 0, &g_gpuCounter);
            PdhCollectQueryData(g_gpuQuery);
        }
    }
}

static int GetGpuUsage() {
    InitGpuQuery();
    if (!g_gpuQuery || !g_gpuCounter) return 0;
    
    PdhCollectQueryData(g_gpuQuery);
    
    DWORD bufferSize = 0;
    DWORD itemCount = 0;
    PdhGetFormattedCounterArrayW(g_gpuCounter, PDH_FMT_DOUBLE, &bufferSize, &itemCount, NULL);
    
    if (bufferSize > 0) {
        std::vector<BYTE> buffer(bufferSize);
        auto* items = reinterpret_cast<PDH_FMT_COUNTERVALUE_ITEM_W*>(buffer.data());
        
        if (PdhGetFormattedCounterArrayW(g_gpuCounter, PDH_FMT_DOUBLE, &bufferSize, &itemCount, items) == ERROR_SUCCESS) {
            double total = 0;
            for (DWORD i = 0; i < itemCount; i++) {
                if (items[i].szName && wcsstr(items[i].szName, L"engtype_3D")) {
                    total += items[i].FmtValue.doubleValue;
                }
            }
            return ClampInt(static_cast<int>(total), 0, 100);
        }
    }
    return 0;
}

// Privacy Registry consent status
bool IsDeviceActiveViaRegistry(const wchar_t* capability) {
    bool isActive = false;
    std::wstring basePath = L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\";
    basePath += capability;

    auto CheckSubkeys = [](HKEY hKeyParent) -> bool {
        DWORD index = 0;
        wchar_t subKeyName[256];
        DWORD nameLen = ARRAYSIZE(subKeyName);
        while (RegEnumKeyExW(hKeyParent, index, subKeyName, &nameLen, nullptr, nullptr, nullptr, nullptr) == ERROR_SUCCESS) {
            HKEY hSub;
            if (RegOpenKeyExW(hKeyParent, subKeyName, 0, KEY_READ, &hSub) == ERROR_SUCCESS) {
                if (_wcsicmp(subKeyName, L"NonPackaged") == 0) {
                    DWORD npIndex = 0;
                    wchar_t npSubKeyName[256];
                    DWORD npNameLen = ARRAYSIZE(npSubKeyName);
                    while (RegEnumKeyExW(hSub, npIndex, npSubKeyName, &npNameLen, nullptr, nullptr, nullptr, nullptr) == ERROR_SUCCESS) {
                        HKEY hNpSub;
                        if (RegOpenKeyExW(hSub, npSubKeyName, 0, KEY_READ, &hNpSub) == ERROR_SUCCESS) {
                            uint64_t stopTime = 1;
                            DWORD dataSize = sizeof(stopTime);
                            if (RegQueryValueExW(hNpSub, L"LastUsedTimeStop", nullptr, nullptr, reinterpret_cast<LPBYTE>(&stopTime), &dataSize) == ERROR_SUCCESS) {
                                if (stopTime == 0) {
                                    RegCloseKey(hNpSub);
                                    RegCloseKey(hSub);
                                    return true;
                                }
                            }
                            RegCloseKey(hNpSub);
                        }
                        npIndex++;
                        npNameLen = ARRAYSIZE(npSubKeyName);
                    }
                } else {
                    uint64_t stopTime = 1;
                    DWORD dataSize = sizeof(stopTime);
                    if (RegQueryValueExW(hSub, L"LastUsedTimeStop", nullptr, nullptr, reinterpret_cast<LPBYTE>(&stopTime), &dataSize) == ERROR_SUCCESS) {
                        if (stopTime == 0) {
                            RegCloseKey(hSub);
                            return true;
                        }
                    }
                }
                RegCloseKey(hSub);
            }
            index++;
            nameLen = ARRAYSIZE(subKeyName);
        }
        return false;
    };

    HKEY hKey;
    if (RegOpenKeyExW(HKEY_CURRENT_USER, basePath.c_str(), 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        isActive = CheckSubkeys(hKey);
        RegCloseKey(hKey);
    }
    return isActive;
}

void UpdatePrivacyIndicators() {
    bool mic = IsDeviceActiveViaRegistry(L"microphone");
    bool cam = IsDeviceActiveViaRegistry(L"webcam");

    std::lock_guard lock(g_stateMutex);
    g_state.system.micActive = mic;
    g_state.system.cameraActive = cam;
}

bool HttpGet(const std::wstring& host, const std::wstring& path, std::string& responseBody) {
    HINTERNET hSession = WinHttpOpen(L"aegisCapsule/0.0.1", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                                     WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
    if (!hSession) return false;

    HINTERNET hConnect = WinHttpConnect(hSession, host.c_str(), INTERNET_DEFAULT_HTTPS_PORT, 0);
    if (!hConnect) {
        WinHttpCloseHandle(hSession);
        return false;
    }

    HINTERNET hRequest = WinHttpOpenRequest(hConnect, L"GET", path.c_str(), nullptr,
                                            WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES,
                                            WINHTTP_FLAG_SECURE);
    if (!hRequest) {
        WinHttpCloseHandle(hConnect);
        WinHttpCloseHandle(hSession);
        return false;
    }

    DWORD timeout = 8000;
    WinHttpSetOption(hRequest, WINHTTP_OPTION_RECEIVE_TIMEOUT, &timeout, sizeof(timeout));

    bool success = false;
    if (WinHttpSendRequest(hRequest, WINHTTP_NO_ADDITIONAL_HEADERS, 0,
                           WINHTTP_NO_REQUEST_DATA, 0, 0, 0) &&
        WinHttpReceiveResponse(hRequest, nullptr)) {
        DWORD size = 0;
        responseBody.clear();
        while (WinHttpQueryDataAvailable(hRequest, &size) && size > 0) {
            std::vector<char> buffer(size);
            DWORD read = 0;
            if (WinHttpReadData(hRequest, buffer.data(), size, &read) && read > 0) {
                responseBody.append(buffer.data(), read);
            }
        }
        success = !responseBody.empty();
    }

    WinHttpCloseHandle(hRequest);
    WinHttpCloseHandle(hConnect);
    WinHttpCloseHandle(hSession);
    return success;
}

void DismissTransientState() {
    std::lock_guard lock(g_stateMutex);
    g_state.clipboard.active = false;
    g_state.notification.active = false;
    g_state.volume.active = false;
    g_state.battery.active = false;
    g_state.capsLock.active = false;
    g_state.device.active = false;
}

void ShowContextMenu(HWND hwnd, POINT screenPoint) {
    HMENU menu = CreatePopupMenu();
    if (!menu) return;

    AppendMenuW(menu, MF_STRING, 1, L"Dismiss current alert / OSD");
    const int pinned = Wh_GetIntValue(L"PinnedExpanded", 0);
    AppendMenuW(menu, MF_STRING, 2, pinned ? L"Pinned Expanded: ON ✓" : L"Pinned Expanded: OFF");
    const int gameOverlayPinned = Wh_GetIntValue(L"GameOverlayPinned", 0);
    AppendMenuW(menu, MF_STRING, 3, gameOverlayPinned ? L"Game Overlay Mode: ON ✓" : L"Game Overlay Mode: OFF");
    
    const int activeExpandOnHover = Wh_GetIntValue(L"ExpandOnHoverOverride", -1) >= 0 
                                  ? Wh_GetIntValue(L"ExpandOnHoverOverride", 0) 
                                  : Wh_GetIntSetting(L"Appearance.ExpandOnHover");
    AppendMenuW(menu, MF_STRING, 11, activeExpandOnHover ? L"Expand on Hover: ON ✓" : L"Expand on Hover: OFF");

    AppendMenuW(menu, MF_SEPARATOR, 0, nullptr);

    // Corner geometry
    const int currentCorner = Wh_GetIntValue(L"CornerStyleOverride", -1) >= 0
                            ? Wh_GetIntValue(L"CornerStyleOverride", 0)
                            : static_cast<int>(GetSettingsSnapshot().cornerStyle);
    AppendMenuW(menu, MF_STRING | (currentCorner == static_cast<int>(CornerStyle::Pill) ? MF_CHECKED : 0), 40, L"Shape: Full Pill");
    AppendMenuW(menu, MF_STRING | (currentCorner == static_cast<int>(CornerStyle::Squircle) ? MF_CHECKED : 0), 41, L"Shape: Vision Squircle");
    AppendMenuW(menu, MF_STRING | (currentCorner == static_cast<int>(CornerStyle::ModernBox) ? MF_CHECKED : 0), 42, L"Shape: Modern 8px Box");
    AppendMenuW(menu, MF_STRING | (currentCorner == static_cast<int>(CornerStyle::Sharp) ? MF_CHECKED : 0), 43, L"Shape: Sharp Minimal Box");

    AppendMenuW(menu, MF_SEPARATOR, 0, nullptr);

    // Liquid Glass Optics switches
    const int activeLiquidGlass = Wh_GetIntValue(L"LiquidGlassOverride", -1) >= 0
                                ? Wh_GetIntValue(L"LiquidGlassOverride", 0)
                                : (Wh_GetIntSetting(L"Optics.LiquidGlass") || Wh_GetIntSetting(L"Themes.LiquidGlass"));
    AppendMenuW(menu, MF_STRING, 30, activeLiquidGlass ? L"Liquid Glass Optics: ON ✓" : L"Liquid Glass Optics: OFF");

    const int activeAccentGlow = Wh_GetIntValue(L"AccentGlowOverride", -1) >= 0
                               ? Wh_GetIntValue(L"AccentGlowOverride", 0)
                               : (Wh_GetIntSetting(L"Optics.AccentGlow") || Wh_GetIntSetting(L"Themes.AccentGlow"));
    AppendMenuW(menu, MF_STRING, 31, activeAccentGlow ? L"Ambient Accent Glow: ON ✓" : L"Ambient Accent Glow: OFF");

    const int activeMetricsInIdle = Wh_GetIntValue(L"ShowMetricsInIdleOverride", -1) >= 0
                                  ? Wh_GetIntValue(L"ShowMetricsInIdleOverride", 0)
                                  : Wh_GetIntSetting(L"Modules.ShowMetricsInIdle");
    AppendMenuW(menu, MF_STRING, 32, activeMetricsInIdle ? L"Show CPU/RAM in Idle: ON ✓" : L"Show CPU/RAM in Idle: OFF");

    AppendMenuW(menu, MF_SEPARATOR, 0, nullptr);
    AppendMenuW(menu, MF_STRING, 4, L"Transparency 100%");
    AppendMenuW(menu, MF_STRING, 5, L"Transparency 85%");
    AppendMenuW(menu, MF_STRING, 6, L"Transparency 70%");
    AppendMenuW(menu, MF_STRING, 7, L"Transparency 55%");
    AppendMenuW(menu, MF_STRING, 8, L"Reset transparency");
    AppendMenuW(menu, MF_SEPARATOR, 0, nullptr);

    // Color theme presets
    AppendMenuW(menu, MF_STRING, 20, L"Theme: OLED Black (default)");
    AppendMenuW(menu, MF_STRING, 21, L"Theme: Dark Gray");
    AppendMenuW(menu, MF_STRING, 22, L"Theme: Midnight Blue");
    AppendMenuW(menu, MF_STRING, 23, L"Theme: Deep Purple");
    AppendMenuW(menu, MF_STRING, 24, L"Theme: Fluent Design");
    AppendMenuW(menu, MF_STRING, 25, L"Theme: Liquid Black 💎");
    AppendMenuW(menu, MF_STRING, 26, L"Theme: Liquid Silver 💎");
    AppendMenuW(menu, MF_STRING, 27, L"Theme: Liquid Night 💎");
    AppendMenuW(menu, MF_STRING, 28, L"Theme: Liquid Aurora 💎");
    AppendMenuW(menu, MF_STRING, 29, L"Theme: Pure Glass (Crystal Clear) 💎");
    AppendMenuW(menu, MF_SEPARATOR, 0, nullptr);
    AppendMenuW(menu, MF_STRING, 50, L"Glass Intensity: 25%");
    AppendMenuW(menu, MF_STRING, 51, L"Glass Intensity: 50%");
    AppendMenuW(menu, MF_STRING, 52, L"Glass Intensity: 75%");
    AppendMenuW(menu, MF_STRING, 53, L"Glass Intensity: 100%");
    AppendMenuW(menu, MF_SEPARATOR, 0, nullptr);
    AppendMenuW(menu, MF_STRING, 60, L"Glow Radius: 16px (Subtle)");
    AppendMenuW(menu, MF_STRING, 61, L"Glow Radius: 24px (Normal)");
    AppendMenuW(menu, MF_STRING, 62, L"Glow Radius: 32px (Wide)");
    AppendMenuW(menu, MF_STRING, 63, L"Glow Radius: 48px (Extra Wide)");
    AppendMenuW(menu, MF_SEPARATOR, 0, nullptr);
    AppendMenuW(menu, MF_STRING, 9, L"Open Windhawk settings");

    SetForegroundWindow(hwnd);
    const UINT cmd = TrackPopupMenu(menu, TPM_RETURNCMD | TPM_RIGHTBUTTON,
                                   screenPoint.x, screenPoint.y, 0, hwnd, nullptr);
    DestroyMenu(menu);

    switch (cmd) {
        case 1:
            DismissTransientState();
            break;
        case 2:
            Wh_SetIntValue(L"PinnedExpanded", Wh_GetIntValue(L"PinnedExpanded", 0) ? 0 : 1);
            g_layoutDirty = true;
            break;
        case 3:
            Wh_SetIntValue(L"GameOverlayPinned", Wh_GetIntValue(L"GameOverlayPinned", 0) ? 0 : 1);
            g_layoutDirty = true;
            break;
        case 4:
            Wh_SetIntValue(L"PillOpacityOverride", 100);
            LoadSettings();
            break;
        case 5:
            Wh_SetIntValue(L"PillOpacityOverride", 85);
            LoadSettings();
            break;
        case 6:
            Wh_SetIntValue(L"PillOpacityOverride", 70);
            LoadSettings();
            break;
        case 7:
            Wh_SetIntValue(L"PillOpacityOverride", 55);
            LoadSettings();
            break;
        case 8:
            Wh_SetIntValue(L"PillOpacityOverride", -1);
            LoadSettings();
            break;
        case 9: {
            wchar_t currentProcessPath[MAX_PATH] = {};
            GetModuleFileNameW(nullptr, currentProcessPath, ARRAYSIZE(currentProcessPath));

            HINSTANCE result = ShellExecuteW(nullptr, L"open",
                                             currentProcessPath,
                                             nullptr,
                                             nullptr, SW_SHOWNORMAL);
            if (reinterpret_cast<INT_PTR>(result) <= 32) {
                Wh_Log(L"Failed to open Windhawk settings.");
            }
            break;
        }
        case 40: // Pill
            Wh_SetIntValue(L"CornerStyleOverride", static_cast<int>(CornerStyle::Pill));
            LoadSettings();
            g_layoutDirty = true;
            break;
        case 41: // Squircle
            Wh_SetIntValue(L"CornerStyleOverride", static_cast<int>(CornerStyle::Squircle));
            LoadSettings();
            g_layoutDirty = true;
            break;
        case 42: // ModernBox
            Wh_SetIntValue(L"CornerStyleOverride", static_cast<int>(CornerStyle::ModernBox));
            LoadSettings();
            g_layoutDirty = true;
            break;
        case 43: // Sharp
            Wh_SetIntValue(L"CornerStyleOverride", static_cast<int>(CornerStyle::Sharp));
            LoadSettings();
            g_layoutDirty = true;
            break;
        case 11: {
            const int activeExpandVal = Wh_GetIntValue(L"ExpandOnHoverOverride", -1) >= 0
                                      ? Wh_GetIntValue(L"ExpandOnHoverOverride", 0)
                                      : Wh_GetIntSetting(L"Appearance.ExpandOnHover");
            Wh_SetIntValue(L"ExpandOnHoverOverride", activeExpandVal ? 0 : 1);
            LoadSettings();
            g_layoutDirty = true;
            break;
        }
        case 30: {
            const int activeLgVal = Wh_GetIntValue(L"LiquidGlassOverride", -1) >= 0
                                  ? Wh_GetIntValue(L"LiquidGlassOverride", 0)
                                  : (Wh_GetIntSetting(L"Optics.LiquidGlass") || Wh_GetIntSetting(L"Themes.LiquidGlass"));
            Wh_SetIntValue(L"LiquidGlassOverride", activeLgVal ? 0 : 1);
            LoadSettings();
            g_layoutDirty = true;
            break;
        }
        case 31: {
            const int activeAgVal = Wh_GetIntValue(L"AccentGlowOverride", -1) >= 0
                                  ? Wh_GetIntValue(L"AccentGlowOverride", 0)
                                  : (Wh_GetIntSetting(L"Optics.AccentGlow") || Wh_GetIntSetting(L"Themes.AccentGlow"));
            Wh_SetIntValue(L"AccentGlowOverride", activeAgVal ? 0 : 1);
            LoadSettings();
            g_layoutDirty = true;
            break;
        }
        case 32: {
            const int activeMetricsVal = Wh_GetIntValue(L"ShowMetricsInIdleOverride", -1) >= 0
                                       ? Wh_GetIntValue(L"ShowMetricsInIdleOverride", 0)
                                       : Wh_GetIntSetting(L"Modules.ShowMetricsInIdle");
            Wh_SetIntValue(L"ShowMetricsInIdleOverride", activeMetricsVal ? 0 : 1);
            LoadSettings();
            g_layoutDirty = true;
            break;
        }
        // Color theme presets
        case 20: Wh_SetIntValue(L"ColorTheme", 0); LoadSettings(); break;
        case 21: Wh_SetIntValue(L"ColorTheme", 1); LoadSettings(); break;
        case 22: Wh_SetIntValue(L"ColorTheme", 2); LoadSettings(); break;
        case 23: Wh_SetIntValue(L"ColorTheme", 3); LoadSettings(); break;
        case 24: Wh_SetIntValue(L"ColorTheme", 4); LoadSettings(); break;
        case 25: Wh_SetIntValue(L"ColorTheme", 5); LoadSettings(); break;
        case 26: Wh_SetIntValue(L"ColorTheme", 6); LoadSettings(); break;
        case 27: Wh_SetIntValue(L"ColorTheme", 7); LoadSettings(); break;
        case 28: Wh_SetIntValue(L"ColorTheme", 8); LoadSettings(); break;
        case 29: Wh_SetIntValue(L"ColorTheme", 9); LoadSettings(); break;
        case 50: Wh_SetIntValue(L"LiquidGlassIntensityOverride", 25); LoadSettings(); break;
        case 51: Wh_SetIntValue(L"LiquidGlassIntensityOverride", 50); LoadSettings(); break;
        case 52: Wh_SetIntValue(L"LiquidGlassIntensityOverride", 75); LoadSettings(); break;
        case 53: Wh_SetIntValue(L"LiquidGlassIntensityOverride", 100); LoadSettings(); break;
        case 60: Wh_SetIntValue(L"AccentGlowRadiusOverride", 16); LoadSettings(); break;
        case 61: Wh_SetIntValue(L"AccentGlowRadiusOverride", 24); LoadSettings(); break;
        case 62: Wh_SetIntValue(L"AccentGlowRadiusOverride", 32); LoadSettings(); break;
        case 63: Wh_SetIntValue(L"AccentGlowRadiusOverride", 48); LoadSettings(); break;
    }
}

class Renderer {
   public:
    bool Initialize(HWND hwnd) {
        hwnd_ = hwnd;

        HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED,
                                       __uuidof(ID2D1Factory),
                                       reinterpret_cast<void**>(d2dFactory_.GetAddressOf()));
        if (FAILED(hr)) return false;

        hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory),
                                 reinterpret_cast<IUnknown**>(dwriteFactory_.GetAddressOf()));
        if (FAILED(hr)) return false;

        D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(
            D2D1_RENDER_TARGET_TYPE_DEFAULT,
            D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED),
            0.0f, 0.0f,
            D2D1_RENDER_TARGET_USAGE_GDI_COMPATIBLE);

        hr = d2dFactory_->CreateDCRenderTarget(&props, &target_);
        if (FAILED(hr)) return false;

        EnsureTextFormats(1.0f);
        return CreateBackingBitmap(520, 140);
    }

    bool CreateBackingBitmap(int width, int height) {
        if (width <= 0 || height <= 0) return false;
        if (bitmapWidth_ == width && bitmapHeight_ == height && memDc_ && memBitmap_) {
            return true;
        }

        HDC screen = GetDC(nullptr);
        if (!memDc_) memDc_ = CreateCompatibleDC(screen);

        BITMAPINFO bi = {};
        bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
        bi.bmiHeader.biWidth = width;
        bi.bmiHeader.biHeight = -height;
        bi.bmiHeader.biPlanes = 1;
        bi.bmiHeader.biBitCount = 32;
        bi.bmiHeader.biCompression = BI_RGB;

        void* bits = nullptr;
        HBITMAP nextBitmap = CreateDIBSection(memDc_, &bi, DIB_RGB_COLORS, &bits, nullptr, 0);
        ReleaseDC(nullptr, screen);

        if (!nextBitmap) return false;

        if (oldBitmap_) SelectObject(memDc_, oldBitmap_);
        if (memBitmap_) DeleteObject(memBitmap_);

        memBitmap_ = nextBitmap;
        oldBitmap_ = SelectObject(memDc_, memBitmap_);
        bitmapWidth_ = width;
        bitmapHeight_ = height;
        return true;
    }

    float lastFontScale_ = 0.0f;
    void EnsureTextFormats(float scale) {
        if (std::abs(scale - lastFontScale_) < 0.001f && textFormat_) {
            return;
        }
        lastFontScale_ = scale;

        textFormat_ = nullptr;
        smallTextFormat_ = nullptr;
        clockFormat_ = nullptr;
        boldTextFormat_ = nullptr;
        hugeTextFormat_ = nullptr;
        iconFormat_ = nullptr;

        dwriteFactory_->CreateTextFormat(L"Segoe UI Variable Display", nullptr,
                                         DWRITE_FONT_WEIGHT_SEMI_BOLD,
                                         DWRITE_FONT_STYLE_NORMAL,
                                         DWRITE_FONT_STRETCH_NORMAL,
                                         13.5f * scale, L"", &textFormat_);
        dwriteFactory_->CreateTextFormat(L"Segoe UI Variable Small", nullptr,
                                         DWRITE_FONT_WEIGHT_NORMAL,
                                         DWRITE_FONT_STYLE_NORMAL,
                                         DWRITE_FONT_STRETCH_NORMAL,
                                         11.0f * scale, L"", &smallTextFormat_);
        dwriteFactory_->CreateTextFormat(L"Segoe UI Variable Display", nullptr,
                                         DWRITE_FONT_WEIGHT_BOLD,
                                         DWRITE_FONT_STYLE_NORMAL,
                                         DWRITE_FONT_STRETCH_NORMAL,
                                         18.0f * scale, L"", &clockFormat_);
        dwriteFactory_->CreateTextFormat(L"Segoe UI Variable Display", nullptr,
                                         DWRITE_FONT_WEIGHT_BOLD,
                                         DWRITE_FONT_STYLE_NORMAL,
                                         DWRITE_FONT_STRETCH_NORMAL,
                                         12.0f * scale, L"", &boldTextFormat_);
        dwriteFactory_->CreateTextFormat(L"Segoe UI Variable Display", nullptr,
                                         DWRITE_FONT_WEIGHT_BOLD,
                                         DWRITE_FONT_STYLE_NORMAL,
                                         DWRITE_FONT_STRETCH_NORMAL,
                                         38.0f * scale, L"", &hugeTextFormat_);
        dwriteFactory_->CreateTextFormat(L"Segoe Fluent Icons", nullptr,
                                         DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STYLE_NORMAL,
                                         DWRITE_FONT_STRETCH_NORMAL,
                                         16.0f * scale, L"", &iconFormat_);

        if (textFormat_) textFormat_->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);
        if (smallTextFormat_) smallTextFormat_->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);
        if (boldTextFormat_) {
            boldTextFormat_->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);
            boldTextFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
        }
        if (hugeTextFormat_) {
            hugeTextFormat_->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);
            hugeTextFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
        }
        if (clockFormat_) {
            clockFormat_->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);
            clockFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
            clockFormat_->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
        }
        if (iconFormat_) iconFormat_->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);
    }

    void EnsureBrushes(const Settings& settings, const SharedState& state) {
        if (!target_) return;

        D2D1_COLOR_F pillColor = settings.pillBgColor;
        pillColor.a *= settings.pillOpacity;
        if (!pillBgBrush_) target_->CreateSolidColorBrush(pillColor, &pillBgBrush_);
        else pillBgBrush_->SetColor(pillColor);

        D2D1_COLOR_F tintColor = D2D1::ColorF(0.0f, 0.0f, 0.0f, settings.tintOpacity * settings.pillOpacity);
        if (!tintBrush_) target_->CreateSolidColorBrush(tintColor, &tintBrush_);
        else tintBrush_->SetColor(tintColor);

        D2D1_COLOR_F accent = settings.customAccent;
        if (settings.accentMode == AccentMode::Auto) {
            if (!state.media.art.bgra.empty()) accent = state.media.art.sampledAccent;
            else accent = settings.customAccent;
        } else if (settings.accentMode == AccentMode::System) {
            DWORD color = 0;
            BOOL opaque = TRUE;
            if (SUCCEEDED(DwmGetColorizationColor(&color, &opaque))) {
                accent = D2D1::ColorF(
                    ((color >> 16) & 0xff) / 255.0f,
                    ((color >> 8) & 0xff) / 255.0f,
                    (color & 0xff) / 255.0f,
                    1.0f);
            }
        }
        if (!accentBrush_) target_->CreateSolidColorBrush(accent, &accentBrush_);
        else accentBrush_->SetColor(accent);

        if (!textBrush_) target_->CreateSolidColorBrush(settings.textPrimaryColor, &textBrush_);
        else textBrush_->SetColor(settings.textPrimaryColor);

        if (!mutedBrush_) target_->CreateSolidColorBrush(settings.textSecondaryColor, &mutedBrush_);
        else mutedBrush_->SetColor(settings.textSecondaryColor);

        if (!whiteBrush_) target_->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 1.0f, 1.0f), &whiteBrush_);
        if (!redBrush_) target_->CreateSolidColorBrush(D2D1::ColorF(1.0f, 0.23f, 0.18f, 1.0f), &redBrush_);
        if (!greenBrush_) target_->CreateSolidColorBrush(D2D1::ColorF(0.0f, 0.90f, 0.46f, 1.0f), &greenBrush_);
        if (!yellowBrush_) target_->CreateSolidColorBrush(D2D1::ColorF(1.0f, 0.85f, 0.0f, 1.0f), &yellowBrush_);
        if (!cyanBrush_) target_->CreateSolidColorBrush(D2D1::ColorF(0.0f, 0.82f, 1.0f, 1.0f), &cyanBrush_);
        if (!orangeBrush_) target_->CreateSolidColorBrush(D2D1::ColorF(1.0f, 0.57f, 0.0f, 1.0f), &orangeBrush_);

        D2D1_COLOR_F rimCol = D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.16f * settings.pillOpacity);
        if (!glassBorderBrush_) target_->CreateSolidColorBrush(rimCol, &glassBorderBrush_);
        else glassBorderBrush_->SetColor(rimCol);

        D2D1_COLOR_F glossCol = D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.35f * settings.pillOpacity);
        if (!glassGlossBrush_) target_->CreateSolidColorBrush(glossCol, &glassGlossBrush_);
        else glassGlossBrush_->SetColor(glossCol);
    }

    void DrawSoftShadow(D2D1_RECT_F rect, float radius, float softness, const Settings& settings) {
        if (!target_) return;
        const int steps = 5;
        float maxSpread = settings.shadowSpreadPx > 0.1f ? settings.shadowSpreadPx : 10.0f * Clamp(softness, 0.1f, 2.0f);
        const float baseAlpha = 0.045f * softness * settingsOpacity_;
        const float yBase = settings.shadowYOffsetPx;

        for (int i = steps; i >= 1; --i) {
            const float spread = (static_cast<float>(i) / steps) * maxSpread;
            const float yOffset = spread * 0.30f + yBase;
            const float alpha = baseAlpha * (1.0f - static_cast<float>(i - 1) / steps * 0.55f);

            D2D1_RECT_F sRect = D2D1::RectF(
                rect.left - spread * 0.5f,
                rect.top - spread * 0.2f + yOffset,
                rect.right + spread * 0.5f,
                rect.bottom + spread * 0.8f + yOffset
            );

            if (!shadowBrushes_[i]) {
                target_->CreateSolidColorBrush(D2D1::ColorF(0.0f, 0.0f, 0.0f, alpha), &shadowBrushes_[i]);
            } else {
                shadowBrushes_[i]->SetOpacity(alpha);
            }

            if (shadowBrushes_[i]) {
                target_->FillRoundedRectangle(
                    D2D1::RoundedRect(sRect, radius + spread * 0.5f, radius + spread * 0.5f),
                    shadowBrushes_[i].Get());
            }
        }
    }

    void DrawAccentGlow(D2D1_RECT_F rect, const Activity& activity, const Settings& settings, double now) {
        if (!accentBrush_ || !target_) return;

        float opacity = (activity.kind == IslandKind::Media ? 0.26f : 0.14f) * settings.accentGlowIntensity;
        if (activity.kind == IslandKind::BatteryLow) {
            if (redBrush_) {
                const float pulse = 0.5f + 0.5f * std::sin(static_cast<float>(now * 4.0));
                redBrush_->SetOpacity((0.20f + 0.15f * pulse) * settingsOpacity_);
                D2D1_RECT_F glowRect = D2D1::RectF(rect.left - 3.0f, rect.top - 2.0f, rect.right + 3.0f, rect.bottom + 3.0f);
                target_->DrawRoundedRectangle(D2D1::RoundedRect(glowRect, (rect.bottom - rect.top) * 0.5f + 2.0f, (rect.bottom - rect.top) * 0.5f + 2.0f), redBrush_.Get(), 2.5f);
                redBrush_->SetOpacity(1.0f);
            }
            return;
        }

        const float pulse = 0.5f + 0.5f * std::sin(static_cast<float>(now * 1.8));
        opacity = (opacity + 0.06f * pulse) * settingsOpacity_;

        const float glowRad = settings.accentGlowRadius;

        // Soft outer ambient halo
        accentBrush_->SetOpacity(opacity * 0.40f);
        D2D1_RECT_F haloRect = D2D1::RectF(rect.left - 3.0f, rect.top - 1.5f, rect.right + 3.0f, rect.bottom + 3.0f);
        target_->DrawRoundedRectangle(D2D1::RoundedRect(haloRect, (rect.bottom - rect.top) * 0.5f + 2.0f, (rect.bottom - rect.top) * 0.5f + 2.0f), accentBrush_.Get(), 2.5f);

        // Soft interior radial spot highlights
        accentBrush_->SetOpacity(opacity * 0.60f);
        target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(rect.left + (rect.right - rect.left) * 0.25f, rect.top + 8.0f), glowRad * 1.5f, glowRad * 0.75f), accentBrush_.Get());
        target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(rect.right - (rect.right - rect.left) * 0.25f, rect.bottom - 6.0f), glowRad * 1.8f, glowRad * 0.8f), accentBrush_.Get());
        accentBrush_->SetOpacity(1.0f);
    }

    void DrawPillSurface(D2D1_RECT_F rect, float radius, IslandKind kind, const Settings& settings, double now) {
        (void)kind;

        // 1. Dark Base Tint
        if (tintBrush_) {
            target_->FillRoundedRectangle(D2D1::RoundedRect(rect, radius, radius), tintBrush_.Get());
        }

        // 2. Base Capsule Color
        if (pillBgBrush_) {
            target_->FillRoundedRectangle(D2D1::RoundedRect(rect, radius, radius), pillBgBrush_.Get());
        }

        // 3. Liquid Glass Multi-Layer Optics Pipeline
        if (settings.liquidGlass && target_) {
            const float intensity = Clamp(settings.liquidGlassIntensity, 0.0f, 1.0f);

            if (settings.glassSheen) {
                const float iOp = intensity * settingsOpacity_;
                if (!sheenBrush_ || cachedSheenIntensity_ != intensity || cachedSheenOpacity_ != settingsOpacity_) {
                    D2D1_GRADIENT_STOP stops[3];
                    stops[0] = {0.0f, D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.16f * iOp)};
                    stops[1] = {0.45f, D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.03f * iOp)};
                    stops[2] = {1.0f, D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.08f * iOp)};
                    sheenStops_ = nullptr;
                    if (SUCCEEDED(target_->CreateGradientStopCollection(stops, 3, &sheenStops_))) {
                        sheenBrush_ = nullptr;
                        target_->CreateLinearGradientBrush(
                            D2D1::LinearGradientBrushProperties(
                                D2D1::Point2F((rect.left + rect.right) * 0.5f, rect.top),
                                D2D1::Point2F((rect.left + rect.right) * 0.5f, rect.bottom)),
                            sheenStops_.Get(), &sheenBrush_);
                        cachedSheenIntensity_ = intensity;
                        cachedSheenOpacity_ = settingsOpacity_;
                    }
                }
                if (sheenBrush_) {
                    target_->FillRoundedRectangle(D2D1::RoundedRect(rect, radius, radius), sheenBrush_.Get());
                }
            }

            if (settings.glassCaustics && !settings.lowPowerMode && settings.causticsSpeed > 0.01f) {
                const float pillW = rect.right - rect.left;
                if (pillW > 40.0f) {
                    const float wavePhase = static_cast<float>(std::sin(now * settings.causticsSpeed));
                    const float waveCenterX = rect.left + pillW * 0.5f + wavePhase * (pillW * 0.35f);
                    const float waveW = std::min(60.0f, pillW * 0.35f);

                    const float sOp = intensity * settingsOpacity_;
                    if (!shimmerBrush_ || cachedShimmerIntensity_ != intensity || cachedShimmerOpacity_ != settingsOpacity_) {
                        D2D1_GRADIENT_STOP shimmerStops[3];
                        shimmerStops[0] = {0.0f, D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.0f)};
                        shimmerStops[1] = {0.5f, D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.08f * sOp)};
                        shimmerStops[2] = {1.0f, D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.0f)};
                        shimmerStops_ = nullptr;
                        if (SUCCEEDED(target_->CreateGradientStopCollection(shimmerStops, 3, &shimmerStops_))) {
                            shimmerBrush_ = nullptr;
                            cachedShimmerIntensity_ = intensity;
                            cachedShimmerOpacity_ = settingsOpacity_;
                        }
                    }
                    if (shimmerStops_) {
                        ComPtr<ID2D1LinearGradientBrush> tmpBrush;
                        target_->CreateLinearGradientBrush(
                            D2D1::LinearGradientBrushProperties(
                                D2D1::Point2F(waveCenterX - waveW, rect.top),
                                D2D1::Point2F(waveCenterX + waveW, rect.top)),
                            shimmerStops_.Get(), &tmpBrush);
                        if (tmpBrush) {
                            target_->FillRoundedRectangle(D2D1::RoundedRect(rect, radius, radius), tmpBrush.Get());
                        }
                    }
                }
            }

            // Crisp 1px Top Specular Rim Reflection
            if (settings.glassSpecular && glassGlossBrush_) {
                glassGlossBrush_->SetOpacity(settings.topHighlightOpacity * intensity * settingsOpacity_);
                D2D1_RECT_F glossLine = D2D1::RectF(rect.left + radius * 0.8f, rect.top + 0.6f,
                                                    rect.right - radius * 0.8f, rect.top + 1.5f);
                target_->FillRectangle(glossLine, glassGlossBrush_.Get());
                glassGlossBrush_->SetOpacity(1.0f);
            }

            // Sub-Pixel Edge Refraction Border
            if (settings.glassRefractionRim && glassBorderBrush_) {
                target_->DrawRoundedRectangle(
                    D2D1::RoundedRect(D2D1::RectF(rect.left + 0.5f, rect.top + 0.5f,
                                                  rect.right - 0.5f, rect.bottom - 0.5f),
                                      radius, radius),
                    glassBorderBrush_.Get(), settings.rimThickness);
            }
        } else {
            if (glassBorderBrush_) {
                target_->DrawRoundedRectangle(
                    D2D1::RoundedRect(D2D1::RectF(rect.left + 0.5f, rect.top + 0.5f,
                                                  rect.right - 0.5f, rect.bottom - 0.5f),
                                      radius, radius),
                    glassBorderBrush_.Get(), settings.rimThickness * 0.9f);
            }
        }
    }

    void DrawPrivacyDots(const SharedState& state, D2D1_RECT_F rect, double now, const Settings& settings) {
        if (!target_ || !d2dFactory_) return;
        const bool micActive = state.system.micActive;
        const bool camActive = state.system.cameraActive;
        if (!micActive && !camActive) return;

        const float dotRadius = settings.privacyDotSize;
        const float spacing = dotRadius * 2.9f;
        const float rightMargin = 14.0f;
        const float cy = (rect.top + rect.bottom) * 0.5f;

        D2D1_POINT_2F camCenter = D2D1::Point2F(rect.right - rightMargin, cy);
        D2D1_POINT_2F micCenter = camActive 
            ? D2D1::Point2F(rect.right - rightMargin - spacing, cy)
            : D2D1::Point2F(rect.right - rightMargin, cy);

        const float pulsePhase = static_cast<float>(std::sin(now * 3.5));
        const float pulseAlpha = 0.6f + 0.4f * pulsePhase;
        const float pulseRadius = dotRadius + 2.5f + 1.5f * pulsePhase;

        if (camActive) {
            D2D1_COLOR_F camColor = D2D1::ColorF(0.0f, 0.90f, 0.46f, 1.0f);
            if (!greenBrush_) target_->CreateSolidColorBrush(camColor, &greenBrush_);
            
            greenBrush_->SetOpacity(0.28f * pulseAlpha * settingsOpacity_);
            target_->FillEllipse(D2D1::Ellipse(camCenter, pulseRadius, pulseRadius), greenBrush_.Get());
            
            greenBrush_->SetOpacity(0.55f * settingsOpacity_);
            target_->FillEllipse(D2D1::Ellipse(camCenter, dotRadius + 1.2f, dotRadius + 1.2f), greenBrush_.Get());
            
            greenBrush_->SetOpacity(1.0f);
            target_->FillEllipse(D2D1::Ellipse(camCenter, dotRadius, dotRadius), greenBrush_.Get());
            
            if (whiteBrush_) {
                whiteBrush_->SetOpacity(0.85f);
                target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(camCenter.x - 1.0f, camCenter.y - 1.0f), 1.2f, 1.2f), whiteBrush_.Get());
                whiteBrush_->SetOpacity(1.0f);
            }
        }

        if (micActive) {
            D2D1_COLOR_F micColor = D2D1::ColorF(1.0f, 0.57f, 0.0f, 1.0f);
            if (!orangeBrush_) target_->CreateSolidColorBrush(micColor, &orangeBrush_);
            
            orangeBrush_->SetOpacity(0.28f * pulseAlpha * settingsOpacity_);
            target_->FillEllipse(D2D1::Ellipse(micCenter, pulseRadius, pulseRadius), orangeBrush_.Get());
            
            orangeBrush_->SetOpacity(0.55f * settingsOpacity_);
            target_->FillEllipse(D2D1::Ellipse(micCenter, dotRadius + 1.2f, dotRadius + 1.2f), orangeBrush_.Get());
            
            orangeBrush_->SetOpacity(1.0f);
            target_->FillEllipse(D2D1::Ellipse(micCenter, dotRadius, dotRadius), orangeBrush_.Get());
            
            if (whiteBrush_) {
                whiteBrush_->SetOpacity(0.85f);
                target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(micCenter.x - 1.0f, micCenter.y - 1.0f), 1.2f, 1.2f), whiteBrush_.Get());
                whiteBrush_->SetOpacity(1.0f);
            }
        }
    }

    void DrawPill(const SharedState& state, const Settings& settings, const Activity& activity,
                  D2D1_RECT_F rect, float scale, double now) {
        const float cx = (rect.left + rect.right) * 0.5f;
        const float cy = (rect.top + rect.bottom) * 0.5f;
        const float w = (rect.right - rect.left) * scale;
        const float h = (rect.bottom - rect.top) * scale;
        rect = D2D1::RectF(cx - w * 0.5f, cy - h * 0.5f, cx + w * 0.5f, cy + h * 0.5f);

        float radius = CalculateCornerRadius(rect.bottom - rect.top, settings);
        
        // Progressive multi-layer soft drop shadow
        if (settings.softShadow && settings.shadowSpreadPx > 0.01f) {
            DrawSoftShadow(rect, radius, settings.shadowSoftness, settings);
        }

        // Dynamic ambient accent glow behind the capsule
        if (settings.accentGlow) {
            DrawAccentGlow(rect, activity, settings, now);
        }

        D2D1_ROUNDED_RECT pill = D2D1::RoundedRect(rect, radius, radius);
        DrawPillSurface(rect, radius, activity.kind, settings, now);

        float contentAlpha = 1.0f;
        if (settings.contentFadeOnResize) {
            float targetW = (activity.kind == IslandKind::Media)
                ? (settings.media ? settings.expandedWidth : settings.collapsedWidth + 40.0f) * settings.sizeScale
                : settings.expandedWidth * settings.sizeScale;
            float targetH = (activity.kind == IslandKind::Media)
                ? settings.expandedHeight * settings.sizeScale
                : settings.expandedHeight * settings.sizeScale;
            float actualW = rect.right - rect.left;
            float actualH = rect.bottom - rect.top;
            if (targetW > 1.0f && targetH > 1.0f) {
                float wRatio = Clamp(actualW / targetW, 0.0f, 1.0f);
                float hRatio = Clamp(actualH / targetH, 0.0f, 1.0f);
                contentAlpha = std::min(wRatio, hRatio);
                contentAlpha = Clamp(contentAlpha, 0.0f, 1.0f);
            }
        }

        if (activity.kind == IslandKind::Progress) {
            DrawProgressRing(rect, state.progress.percent, settings);
        }

        if (activity.kind == IslandKind::BatteryLow) {
            const float pulse = 0.5f + 0.5f * std::sin(static_cast<float>(now * 2.0 * 3.14159265 * 2.1));
            redBrush_->SetOpacity(0.45f + 0.45f * pulse);
            target_->DrawRoundedRectangle(pill, redBrush_.Get(), 2.0f);
            redBrush_->SetOpacity(1.0f);
        } else {
            accentBrush_->SetOpacity(activity.kind == IslandKind::Idle ? 0.18f : 0.34f);
            target_->DrawRoundedRectangle(pill, accentBrush_.Get(), 1.0f);
            accentBrush_->SetOpacity(1.0f);
        }

        if (radius > 2.0f) {
            if (whiteBrush_) {
                whiteBrush_->SetOpacity(0.08f * settingsOpacity_);
                target_->DrawRoundedRectangle(
                    D2D1::RoundedRect(D2D1::RectF(rect.left + 1, rect.top + 1, rect.right - 1,
                                                  rect.bottom - 1),
                                      std::max(0.0f, radius - 1.0f), std::max(0.0f, radius - 1.0f)),
                    whiteBrush_.Get(), 1.0f);
                whiteBrush_->SetOpacity(1.0f);
            }
        }

        D2D1_MATRIX_3X2_F oldTransform;
        target_->GetTransform(&oldTransform);
        D2D1_POINT_2F pillCenter = D2D1::Point2F((rect.left + rect.right) * 0.5f, (rect.top + rect.bottom) * 0.5f);
        target_->SetTransform(D2D1::Matrix3x2F::Scale(settings.sizeScale, settings.sizeScale, pillCenter) * oldTransform);

        float invScale = 1.0f / (settings.sizeScale > 0.01f ? settings.sizeScale : 1.0f);
        float unW = (rect.right - rect.left) * invScale;
        float unH = (rect.bottom - rect.top) * invScale;
        D2D1_RECT_F unscaledRect = D2D1::RectF(pillCenter.x - unW * 0.5f, pillCenter.y - unH * 0.5f, pillCenter.x + unW * 0.5f, pillCenter.y + unH * 0.5f);

        if (contentAlpha < 0.99f && textBrush_ && mutedBrush_) {
            textBrush_->SetOpacity(contentAlpha);
            mutedBrush_->SetOpacity(contentAlpha * 0.58f);
        }

        switch (activity.kind) {
            case IslandKind::Media:
                DrawMedia(state, unscaledRect, now);
                break;
            case IslandKind::Clipboard:
                DrawClipboard(state, unscaledRect);
                break;
            case IslandKind::Notification:
                DrawNotification(state, unscaledRect);
                break;
            case IslandKind::Volume:
                DrawVolume(state, unscaledRect);
                break;
            case IslandKind::CapsLock:
                DrawCapsLock(state, unscaledRect);
                break;
            case IslandKind::Device:
                DrawDevice(state, unscaledRect);
                break;
            case IslandKind::BatteryLow:
                DrawBattery(state, unscaledRect);
                break;
            case IslandKind::Progress:
                DrawProgress(state, unscaledRect);
                break;
            case IslandKind::Idle:
            default:
                DrawIdleDashboard(state, unscaledRect, settings, now);
                break;
        }

        // Apple-style privacy indicator dots
        DrawPrivacyDots(state, unscaledRect, now, settings);

        if (contentAlpha < 0.99f && textBrush_ && mutedBrush_) {
            textBrush_->SetOpacity(0.90f);
            mutedBrush_->SetOpacity(0.58f);
        }

        target_->SetTransform(oldTransform);
    }

    static void GetWeatherIconAndText(int code, std::wstring& icon, std::wstring& text) {
        switch (code) {
            case 113: icon = L"☀️"; text = L"Sunny"; break;
            case 116: icon = L"⛅"; text = L"Partly Cloudy"; break;
            case 119: case 122: icon = L"☁️"; text = L"Cloudy"; break;
            case 143: case 248: case 260: icon = L"🌫️"; text = L"Foggy"; break;
            case 200: case 386: case 389: case 392: case 395: icon = L"⛈️"; text = L"Thunderstorm"; break;
            case 176: case 263: case 266: case 281: case 284: case 293: case 296: case 299: case 302: case 305: case 308: case 311: case 314: case 353: case 356: case 359: icon = L"🌧️"; text = L"Rain"; break;
            case 179: case 182: case 185: case 227: case 230: case 317: case 320: case 323: case 326: case 329: case 332: case 335: case 338: case 350: case 362: case 365: case 368: case 371: icon = L"❄️"; text = L"Snow"; break;
            default: icon = L"🌡️"; text = L"Clear"; break;
        }
    }

    static int GetDaysInMonth(int year, int month) {
        if (month == 2) {
            bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            return leap ? 29 : 28;
        }
        if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
        return 31;
    }

    static int GetDayOfWeek(int year, int month, int day) {
        if (month < 3) { month += 12; year -= 1; }
        int k = year % 100;
        int j = year / 100;
        int h = (day + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
        return (h + 6) % 7;
    }

    void DrawCalendarDashboard(const SharedState& state, D2D1_RECT_F rect, const Settings& settings, double now, float scale, SYSTEMTIME& local) {
        (void)state; (void)settings; (void)now;
        ComPtr<ID2D1SolidColorBrush> calBg;
        target_->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.04f * settingsOpacity_), &calBg);
        D2D1_RECT_F leftBlock = D2D1::RectF(rect.left + 22.0f * scale, rect.top + 16.0f * scale,
                                            rect.left + 115.0f * scale, rect.bottom - 22.0f * scale);
        target_->FillRoundedRectangle(D2D1::RoundedRect(leftBlock, 12.0f * scale, 12.0f * scale), calBg.Get());
        
        ComPtr<ID2D1SolidColorBrush> calHeader;
        target_->CreateSolidColorBrush(D2D1::ColorF(0.85f, 0.25f, 0.20f, 0.9f * settingsOpacity_), &calHeader);
        
        wchar_t monthName[32] = {};
        GetDateFormatEx(LOCALE_NAME_USER_DEFAULT, 0, &local, L"MMMM", monthName, ARRAYSIZE(monthName), nullptr);
        for (int i = 0; monthName[i]; ++i) monthName[i] = towupper(monthName[i]);
        
        target_->DrawTextW(monthName, static_cast<UINT32>(wcslen(monthName)), boldTextFormat_.Get(),
                           D2D1::RectF(leftBlock.left, leftBlock.top + 6.0f * scale, leftBlock.right, leftBlock.top + 24.0f * scale),
                           calHeader.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);

        wchar_t yearStr[16] = {};
        swprintf_s(yearStr, L"%d", local.wYear);
        mutedBrush_->SetOpacity(0.45f);
        target_->DrawTextW(yearStr, static_cast<UINT32>(wcslen(yearStr)), boldTextFormat_.Get(),
                           D2D1::RectF(leftBlock.left, leftBlock.top + 20.0f * scale, leftBlock.right, leftBlock.top + 38.0f * scale),
                           mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
        mutedBrush_->SetOpacity(1.0f);

        wchar_t dayStr[16] = {};
        swprintf_s(dayStr, L"%d", local.wDay);
        textBrush_->SetOpacity(0.96f);
        target_->DrawTextW(dayStr, static_cast<UINT32>(wcslen(dayStr)), hugeTextFormat_.Get(),
                           D2D1::RectF(leftBlock.left, leftBlock.top + 30.0f * scale, leftBlock.right, leftBlock.top + 80.0f * scale),
                           textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
        textBrush_->SetOpacity(1.0f);

        wchar_t weekdayName[32] = {};
        GetDateFormatEx(LOCALE_NAME_USER_DEFAULT, 0, &local, L"dddd", weekdayName, ARRAYSIZE(weekdayName), nullptr);
        mutedBrush_->SetOpacity(0.75f);
        target_->DrawTextW(weekdayName, static_cast<UINT32>(wcslen(weekdayName)), boldTextFormat_.Get(),
                           D2D1::RectF(leftBlock.left, leftBlock.bottom - 22.0f * scale, leftBlock.right, leftBlock.bottom),
                           mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
        mutedBrush_->SetOpacity(1.0f);

        // Right Grid
        const float gridStart = rect.left + 144.0f * scale;
        const float gridTop = rect.top + 30.0f * scale;
        const float colW = 31.0f * scale;
        const float rowH = 18.0f * scale;
        const wchar_t* days[] = {L"S", L"M", L"T", L"W", L"T", L"F", L"S"};
        
        for (int i = 0; i < 7; ++i) {
            D2D1_RECT_F cell = D2D1::RectF(gridStart + i * colW, gridTop, gridStart + (i+1)*colW, gridTop + rowH);
            ComPtr<ID2D1SolidColorBrush> brush = (i == 0 || i == 6) ? calHeader : mutedBrush_;
            target_->DrawTextW(days[i], 1, boldTextFormat_.Get(), cell, brush.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
        }

        int startDay = GetDayOfWeek(local.wYear, local.wMonth, 1);
        int totalDays = GetDaysInMonth(local.wYear, local.wMonth);
        
        int row = 1;
        int col = startDay;
        
        ComPtr<ID2D1SolidColorBrush> weekendBrush;
        target_->CreateSolidColorBrush(D2D1::ColorF(0.85f, 0.25f, 0.20f, 0.65f * settingsOpacity_), &weekendBrush);

        for (int d = 1; d <= totalDays; ++d) {
            D2D1_RECT_F cell = D2D1::RectF(gridStart + col * colW, gridTop + row * rowH + 4.0f * scale, 
                                           gridStart + (col+1)*colW, gridTop + (row+1)*rowH + 4.0f * scale);
            
            if (d == local.wDay) {
                target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(cell.left + colW*0.5f, cell.top + rowH*0.5f), 10.0f*scale, 10.0f*scale), calHeader.Get());
                textBrush_->SetOpacity(1.0f);
                target_->DrawTextW(std::to_wstring(d).c_str(), static_cast<UINT32>(std::to_wstring(d).length()), boldTextFormat_.Get(), cell, textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
            } else {
                if (col == 0 || col == 6) {
                    target_->DrawTextW(std::to_wstring(d).c_str(), static_cast<UINT32>(std::to_wstring(d).length()), boldTextFormat_.Get(), cell, weekendBrush.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
                } else {
                    textBrush_->SetOpacity(0.85f);
                    target_->DrawTextW(std::to_wstring(d).c_str(), static_cast<UINT32>(std::to_wstring(d).length()), boldTextFormat_.Get(), cell, textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
                }
            }
            
            col++;
            if (col > 6) { col = 0; row++; }
        }
        textBrush_->SetOpacity(1.0f);
    }

    void DrawWeatherDashboard(const SharedState& state, D2D1_RECT_F rect, const Settings& settings, double now, float scale, bool hasWeather, const std::wstring& wIcon, const std::wstring& wText) {
        (void)now;
        wchar_t wTemp[32] = {};
        if (hasWeather) swprintf_s(wTemp, L"%.0f\x00B0", state.weather.temperature);
        else wcscpy_s(wTemp, L"--\x00B0");

        std::wstring city = hasWeather ? state.weather.city : L"Locating...";
        std::wstring desc = wText;

        textBrush_->SetOpacity(0.96f);
        target_->DrawTextW(city.c_str(), static_cast<UINT32>(city.length()), boldTextFormat_.Get(),
                           D2D1::RectF(rect.left + 35.0f * scale, rect.top + 35.0f * scale, rect.left + 185.0f * scale, rect.bottom),
                           textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);

        target_->DrawTextW(wIcon.c_str(), static_cast<UINT32>(wIcon.length()), hugeTextFormat_.Get(),
                           D2D1::RectF(rect.left + 35.0f * scale, rect.top + 60.0f * scale, rect.left + 95.0f * scale, rect.bottom),
                           textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_ENABLE_COLOR_FONT);
                           
        target_->DrawTextW(wTemp, static_cast<UINT32>(wcslen(wTemp)), hugeTextFormat_.Get(),
                           D2D1::RectF(rect.left + 95.0f * scale, rect.top + 60.0f * scale, rect.left + 185.0f * scale, rect.bottom),
                           textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);

        mutedBrush_->SetOpacity(0.85f);
        target_->DrawTextW(desc.c_str(), static_cast<UINT32>(desc.length()), textFormat_.Get(),
                           D2D1::RectF(rect.left + 35.0f * scale, rect.top + 120.0f * scale, rect.left + 185.0f * scale, rect.bottom),
                           mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);

        ComPtr<ID2D1SolidColorBrush> divider;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.12f * settingsOpacity_), &divider);
        target_->FillRoundedRectangle(
            D2D1::RoundedRect(D2D1::RectF(rect.left + 190.0f * scale, rect.top + 30.0f * scale,
                                           rect.left + 191.5f * scale, rect.bottom - 34.0f * scale),
                              0.5f * scale, 0.5f * scale), divider.Get());

        std::wstring line3 = hasWeather ? L"Wind: " + state.weather.windSpeed + (settings.weatherFahrenheit ? L" mph " : L" km/h ") + state.weather.windDir : L"Updated recently";
        std::wstring line4 = hasWeather ? L"Feels Like: " + state.weather.feelsLike + L"\x00B0" : L"";
        std::wstring line5 = hasWeather ? L"Humidity: " + state.weather.humidity + L"%" : L"";

        mutedBrush_->SetOpacity(0.70f);
        D2D1_RECT_F rightLine3 = D2D1::RectF(rect.left + 215.0f * scale, rect.top + 55.0f * scale, rect.right, rect.bottom);
        target_->DrawTextW(line3.c_str(), static_cast<UINT32>(line3.length()), textFormat_.Get(),
                           rightLine3, mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
                           
        D2D1_RECT_F rightLine4 = D2D1::RectF(rect.left + 215.0f * scale, rect.top + 85.0f * scale, rect.right, rect.bottom);
        target_->DrawTextW(line4.c_str(), static_cast<UINT32>(line4.length()), textFormat_.Get(),
                           rightLine4, mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
                           
        D2D1_RECT_F rightLine5 = D2D1::RectF(rect.left + 215.0f * scale, rect.top + 115.0f * scale, rect.right, rect.bottom);
        target_->DrawTextW(line5.c_str(), static_cast<UINT32>(line5.length()), textFormat_.Get(),
                           rightLine5, mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
        mutedBrush_->SetOpacity(1.0f);
        textBrush_->SetOpacity(1.0f);
    }

    void DrawIdleDashboard(const SharedState& state, D2D1_RECT_F rect, const Settings& settings,
                           double now) {
        if (settings.gameOverlay || Wh_GetIntValue(L"GameOverlayPinned", 0) != 0) {
            DrawGameOverlay(state, rect, 1.0f);
            return;
        }
        target_->PushAxisAlignedClip(rect, D2D1_ANTIALIAS_MODE_PER_PRIMITIVE);
        
        if (!clockFormat_) {
            target_->PopAxisAlignedClip();
            return;
        }

        SYSTEMTIME local = {};
        GetLocalTime(&local);
        wchar_t timeBuf[32] = {};
        GetTimeFormatEx(LOCALE_NAME_USER_DEFAULT, TIME_NOSECONDS, &local, nullptr, timeBuf, ARRAYSIZE(timeBuf));

        const float scale = 1.0f;
        const float width = rect.right - rect.left;
        
        bool hasWeather = state.weather.hasData && (now - state.weather.lastUpdated < 3600.0);
        std::wstring wIcon = L"🌡️";
        std::wstring wText = L"Loading...";
        if (hasWeather) {
            wText = state.weather.weatherDesc;
            GetWeatherIconAndText(state.weather.weatherCode, wIcon, wText);
        }

        if (width / scale < 220.0f) {
            // Collapsed Mode
            D2D1_RECT_F timeRect = D2D1::RectF(rect.left + 16.0f * scale, rect.top + 7.0f * scale,
                                               rect.left + 72.0f * scale, rect.bottom - 7.0f * scale);
            textBrush_->SetOpacity(0.96f);
            target_->DrawTextW(timeBuf, static_cast<UINT32>(wcslen(timeBuf)), smallTextFormat_.Get(),
                               timeRect, textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
            
            ComPtr<ID2D1SolidColorBrush> divider;
            target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.12f * settingsOpacity_), &divider);
            target_->FillRoundedRectangle(
                D2D1::RoundedRect(D2D1::RectF(rect.left + 74.0f * scale, rect.top + 10.0f * scale,
                                               rect.left + 75.5f * scale, rect.bottom - 10.0f * scale),
                                  0.5f * scale, 0.5f * scale), divider.Get());

            if (settings.showMetricsInIdle && state.system.cpuPercent >= 0) {
                wchar_t cpuLabel[32] = {};
                swprintf_s(cpuLabel, L"%d%%", state.system.cpuPercent);
                D2D1_RECT_F cpuRect = D2D1::RectF(rect.left + 82.0f * scale, rect.top + 7.0f * scale,
                                                  rect.left + 118.0f * scale, rect.bottom - 7.0f * scale);
                accentBrush_->SetOpacity(0.85f);
                target_->DrawTextW(cpuLabel, static_cast<UINT32>(wcslen(cpuLabel)), smallTextFormat_.Get(),
                                   cpuRect, accentBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
                accentBrush_->SetOpacity(1.0f);
            }

            wchar_t weatherLabel[32] = {};
            if (hasWeather) swprintf_s(weatherLabel, L"%s %.0f\x00B0", wIcon.c_str(), state.weather.temperature);
            else wcscpy_s(weatherLabel, ARRAYSIZE(weatherLabel), L"🌡️ --\x00B0");

            const float weatherLeft = (settings.showMetricsInIdle ? 122.0f : 86.0f) * scale;
            D2D1_RECT_F wRect = D2D1::RectF(rect.left + weatherLeft, rect.top + 7.0f * scale,
                                            rect.right - 8.0f * scale, rect.bottom - 7.0f * scale);
            target_->DrawTextW(weatherLabel, static_cast<UINT32>(wcslen(weatherLabel)), smallTextFormat_.Get(),
                               wRect, textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_ENABLE_COLOR_FONT);
            textBrush_->SetOpacity(1.0f);
            target_->PopAxisAlignedClip();
            return;
        }

        // Expanded Mode
        int tab = Modulo(g_idleTab.load(), 2);
        if (tab == 0) DrawCalendarDashboard(state, rect, settings, now, scale, local);
        else DrawWeatherDashboard(state, rect, settings, now, scale, hasWeather, wIcon, wText);

        // Pagination dots (Vertical on the right edge)
        float shiftX = 0.0f;
        if (state.system.micActive && state.system.cameraActive) shiftX = 30.0f * scale;
        else if (state.system.micActive || state.system.cameraActive) shiftX = 16.0f * scale;

        const float dotX = rect.right - 10.0f * scale - shiftX;
        const float dotY = (rect.top + rect.bottom) * 0.5f;
        const float spacing = 8.0f * scale;
        const float r = settings.paginationDotSize * scale;
        
        ComPtr<ID2D1SolidColorBrush> activeDot, inactiveDot;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.85f * settingsOpacity_), &activeDot);
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.25f * settingsOpacity_), &inactiveDot);

        target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(dotX, dotY - spacing * 0.5f), r, r), tab == 0 ? activeDot.Get() : inactiveDot.Get());
        target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(dotX, dotY + spacing * 0.5f), r, r), tab == 1 ? activeDot.Get() : inactiveDot.Get());

        target_->PopAxisAlignedClip();
    }

    void DrawGameOverlay(const SharedState& state, D2D1_RECT_F rect, float scale) {
        Settings settings = GetSettingsSnapshot();
        ComPtr<ID2D1SolidColorBrush> panelBrush;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.080f * settingsOpacity_), &panelBrush);

        D2D1_RECT_F fpsPanel = D2D1::RectF(rect.left + 10.0f * scale, rect.top + 10.0f * scale,
                                          rect.left + 84.0f * scale, rect.bottom - 10.0f * scale);
        target_->FillRoundedRectangle(D2D1::RoundedRect(fpsPanel, 15.0f * scale, 15.0f * scale), panelBrush.Get());

        ComPtr<ID2D1SolidColorBrush> fpsIconBrush;
        target_->CreateSolidColorBrush(D2D1::ColorF(0.0f, 1.0f, 0.65f, 1.0f), &fpsIconBrush);
        D2D1_POINT_2F fpsCenter = D2D1::Point2F(fpsPanel.left + 18.0f * scale, fpsPanel.top + 17.0f * scale);
        DrawGameIcon(fpsCenter, 7.0f * scale, 0, fpsIconBrush.Get(), scale);

        if (settings.showMetricText) {
            mutedBrush_->SetOpacity(0.44f);
            target_->DrawTextW(L"FPS", 3, smallTextFormat_.Get(),
                               D2D1::RectF(fpsPanel.left + 31.0f * scale, fpsPanel.top + 6.0f * scale,
                                           fpsPanel.right - 10.0f * scale, fpsPanel.top + 24.0f * scale),
                               mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
        }

        wchar_t fpsValue[16] = {};
        swprintf_s(fpsValue, L"%d", state.system.renderFps);
        textBrush_->SetOpacity(0.96f);
        D2D1_RECT_F fpsValueRect = settings.showMetricText 
            ? D2D1::RectF(fpsPanel.left + 16.0f * scale, fpsPanel.top + 23.0f * scale, fpsPanel.right - 10.0f * scale, fpsPanel.bottom - 4.0f * scale)
            : D2D1::RectF(fpsPanel.left + 31.0f * scale, fpsPanel.top + 10.0f * scale, fpsPanel.right - 10.0f * scale, fpsPanel.bottom - 4.0f * scale);
        target_->DrawTextW(fpsValue, static_cast<UINT32>(wcslen(fpsValue)), textFormat_.Get(),
                           fpsValueRect, textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);

        const float cardTop = rect.top + 10.0f * scale;
        const float cardW = 62.0f * scale;
        const float gap = 6.0f * scale;
        const float start = fpsPanel.right + 8.0f * scale;
        DrawGameMetricCard(D2D1::RectF(start, cardTop, start + cardW, rect.bottom - 10.0f * scale),
                           L"CPU", state.system.cpuPercent, 1, scale);
        DrawGameMetricCard(D2D1::RectF(start + cardW + gap, cardTop,
                                       start + cardW * 2.0f + gap, rect.bottom - 10.0f * scale),
                           L"RAM", state.system.memoryPercent, 2, scale);
        DrawGameMetricCard(D2D1::RectF(start + cardW * 2.0f + gap * 2.0f, cardTop,
                                       start + cardW * 3.0f + gap * 2.0f, rect.bottom - 10.0f * scale),
                           L"GPU", state.system.gpuPercent, 3, scale);
        DrawGameMetricCard(D2D1::RectF(start + cardW * 3.0f + gap * 3.0f, cardTop,
                                       start + cardW * 4.0f + gap * 3.0f, rect.bottom - 10.0f * scale),
                           L"DSK", 100 - state.system.diskFreePercent, 4, scale);

        textBrush_->SetOpacity(0.90f);
        mutedBrush_->SetOpacity(0.58f);
    }

    void DrawGameMetricCard(D2D1_RECT_F rect, const wchar_t* label, int percent, int iconKind, float scale) {
        Settings settings = GetSettingsSnapshot();
        D2D1_COLOR_F metricColor = D2D1::ColorF(0.0f, 0.82f, 1.0f, 1.0f);
        switch (iconKind) {
            case 1: metricColor = D2D1::ColorF(0.0f, 0.82f, 1.0f, 1.0f); break;
            case 2: metricColor = D2D1::ColorF(0.83f, 0.0f, 1.0f, 1.0f); break;
            case 3: metricColor = D2D1::ColorF(0.0f, 1.0f, 0.60f, 1.0f); break;
            case 4: metricColor = D2D1::ColorF(1.0f, 0.48f, 0.0f, 1.0f); break;
            default: metricColor = D2D1::ColorF(0.0f, 1.0f, 0.65f, 1.0f); break;
        }

        ComPtr<ID2D1SolidColorBrush> metricBrush;
        target_->CreateSolidColorBrush(metricColor, &metricBrush);

        ComPtr<ID2D1SolidColorBrush> cardBrush;
        ComPtr<ID2D1SolidColorBrush> borderBrush;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.080f * settingsOpacity_), &cardBrush);
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.060f * settingsOpacity_), &borderBrush);
        target_->FillRoundedRectangle(D2D1::RoundedRect(rect, 16.0f * scale, 16.0f * scale), cardBrush.Get());
        target_->DrawRoundedRectangle(D2D1::RoundedRect(rect, 16.0f * scale, 16.0f * scale), borderBrush.Get(), 1.0f * scale);

        metricBrush->SetOpacity(0.24f * settingsOpacity_);
        target_->DrawRoundedRectangle(D2D1::RoundedRect(rect, 16.0f * scale, 16.0f * scale), metricBrush.Get(), 1.2f * scale);
        metricBrush->SetOpacity(1.0f);

        DrawGameIcon(D2D1::Point2F(rect.left + 18.0f * scale, rect.top + 18.0f * scale), 8.0f * scale, iconKind, metricBrush.Get(), scale);

        if (settings.showMetricText) {
            mutedBrush_->SetOpacity(0.56f);
            target_->DrawTextW(label, static_cast<UINT32>(wcslen(label)), smallTextFormat_.Get(),
                               D2D1::RectF(rect.left + 31.0f * scale, rect.top + 6.0f * scale,
                                           rect.right - 5.0f * scale, rect.top + 24.0f * scale),
                               mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
        }

        wchar_t value[16] = {};
        if (percent < 0) wcscpy_s(value, ARRAYSIZE(value), L"--");
        else swprintf_s(value, L"%d%%", percent);
        textBrush_->SetOpacity(0.90f);
        D2D1_RECT_F valueRect = settings.showMetricText 
            ? D2D1::RectF(rect.left + 10.0f * scale, rect.top + 22.0f * scale, rect.right - 8.0f * scale, rect.bottom - 8.0f * scale)
            : D2D1::RectF(rect.left + 31.0f * scale, rect.top + 10.0f * scale, rect.right - 5.0f * scale, rect.bottom - 8.0f * scale);
        target_->DrawTextW(value, static_cast<UINT32>(wcslen(value)), textFormat_.Get(),
                           valueRect, textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);

        const float pct = percent < 0 ? 0.0f : Clamp(percent / 100.0f, 0.0f, 1.0f);
        D2D1_RECT_F track = D2D1::RectF(rect.left + 10.0f * scale, rect.bottom - 6.0f * scale,
                                       rect.right - 10.0f * scale, rect.bottom - 3.0f * scale);
        borderBrush->SetOpacity(0.12f * settingsOpacity_);
        target_->FillRoundedRectangle(D2D1::RoundedRect(track, 1.5f * scale, 1.5f * scale), borderBrush.Get());
        D2D1_RECT_F fillRect = D2D1::RectF(track.left, track.top,
                                          track.left + (track.right - track.left) * pct,
                                          track.bottom);
        metricBrush->SetOpacity(0.85f);
        target_->FillRoundedRectangle(D2D1::RoundedRect(fillRect, 1.5f * scale, 1.5f * scale), metricBrush.Get());
        metricBrush->SetOpacity(1.0f);
    }

    void DrawGameIcon(D2D1_POINT_2F center, float radius, int kind, ID2D1SolidColorBrush* customBrush, float scale) {
        ID2D1SolidColorBrush* brush = customBrush ? customBrush : accentBrush_.Get();
        if (!brush) return;
        brush->SetOpacity(0.88f);
        switch (kind) {
            case 1: { // CPU die
                const float size = radius * 0.82f;
                D2D1_RECT_F outerRect = D2D1::RectF(center.x - size, center.y - size, center.x + size, center.y + size);
                target_->DrawRoundedRectangle(D2D1::RoundedRect(outerRect, 2.0f * scale, 2.0f * scale), brush, 1.4f * scale);
                const float dieSize = size * 0.45f;
                D2D1_RECT_F dieRect = D2D1::RectF(center.x - dieSize, center.y - dieSize, center.x + dieSize, center.y + dieSize);
                target_->FillRoundedRectangle(D2D1::RoundedRect(dieRect, 1.0f * scale, 1.0f * scale), brush);
                break;
            }
            case 2: { // RAM
                const float w = radius * 1.15f;
                const float h = radius * 0.45f;
                D2D1_RECT_F pcb = D2D1::RectF(center.x - w, center.y - h, center.x + w, center.y + h);
                target_->DrawRoundedRectangle(D2D1::RoundedRect(pcb, 1.0f * scale, 1.0f * scale), brush, 1.3f * scale);
                break;
            }
            case 3: { // GPU Fan
                const float fanR = radius * 0.75f;
                target_->DrawEllipse(D2D1::Ellipse(center, fanR, fanR), brush, 1.2f * scale);
                target_->FillEllipse(D2D1::Ellipse(center, 1.8f * scale, 1.8f * scale), brush);
                break;
            }
            case 4: { // Disk
                const float w = radius * 0.85f;
                const float h = radius * 1.05f;
                D2D1_RECT_F enc = D2D1::RectF(center.x - w, center.y - h, center.x + w, center.y + h);
                target_->DrawRoundedRectangle(D2D1::RoundedRect(enc, 2.0f * scale, 2.0f * scale), brush, 1.3f * scale);
                break;
            }
            case 0:
            default: { // Speedometer
                const float dialR = radius * 1.05f;
                target_->DrawEllipse(D2D1::Ellipse(center, dialR, dialR), brush, 1.3f * scale);
                target_->FillEllipse(D2D1::Ellipse(center, 1.6f * scale, 1.6f * scale), brush);
                break;
            }
        }
        brush->SetOpacity(1.0f);
    }

    void DrawMetricChip(const SharedState& state, D2D1_RECT_F rect, const wchar_t* label, int percent, int iconKind) {
        Settings settings = GetSettingsSnapshot();
        const float scale = 1.0f;
        D2D1_COLOR_F metricColor = D2D1::ColorF(0.0f, 0.82f, 1.0f, 1.0f);
        switch (iconKind) {
            case 1: {
                if (state.battery.low) metricColor = D2D1::ColorF(1.0f, 0.23f, 0.18f, 1.0f);
                else if (state.system.charging) metricColor = D2D1::ColorF(1.0f, 0.80f, 0.0f, 1.0f);
                else metricColor = D2D1::ColorF(0.0f, 0.90f, 0.50f, 1.0f);
                break;
            }
            case 2: metricColor = D2D1::ColorF(0.0f, 0.65f, 1.0f, 1.0f); break;
            case 3: default: metricColor = D2D1::ColorF(0.83f, 0.0f, 1.0f, 1.0f); break;
        }

        ComPtr<ID2D1SolidColorBrush> metricBrush;
        target_->CreateSolidColorBrush(metricColor, &metricBrush);

        ComPtr<ID2D1SolidColorBrush> chipBg, chipBorder;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.070f * settingsOpacity_), &chipBg);
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.060f * settingsOpacity_), &chipBorder);
        target_->FillRoundedRectangle(D2D1::RoundedRect(rect, 11.0f * scale, 11.0f * scale), chipBg.Get());
        target_->DrawRoundedRectangle(D2D1::RoundedRect(rect, 11.0f * scale, 11.0f * scale), chipBorder.Get(), 1.0f * scale);

        metricBrush->SetOpacity(0.24f * settingsOpacity_);
        target_->DrawRoundedRectangle(D2D1::RoundedRect(rect, 11.0f * scale, 11.0f * scale), metricBrush.Get(), 1.2f * scale);
        metricBrush->SetOpacity(1.0f);

        if (settings.showMetricText) {
            D2D1_RECT_F labelRect = D2D1::RectF(rect.left + 23.0f * scale, rect.top + 3.0f * scale, rect.right - 2.0f * scale, rect.top + 20.0f * scale);
            mutedBrush_->SetOpacity(0.48f);
            target_->DrawTextW(label, static_cast<UINT32>(wcslen(label)), smallTextFormat_.Get(), labelRect,
                               mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
        }

        wchar_t value[16] = {};
        if (percent < 0) wcscpy_s(value, ARRAYSIZE(value), L"--");
        else swprintf_s(value, L"%d%%", percent);
        textBrush_->SetOpacity(0.90f);
        D2D1_RECT_F valueRect = settings.showMetricText
            ? D2D1::RectF(rect.left + 7.5f * scale, rect.top + 14.5f * scale, rect.right - 2.0f * scale, rect.bottom - 8.0f * scale)
            : D2D1::RectF(rect.left + 23.0f * scale, rect.top + 8.0f * scale, rect.right - 2.0f * scale, rect.bottom - 8.0f * scale);
        target_->DrawTextW(value, static_cast<UINT32>(wcslen(value)), textFormat_.Get(),
                           valueRect, textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);

        const float clamped = percent < 0 ? 0.0f : Clamp(percent / 100.0f, 0.0f, 1.0f);
        D2D1_RECT_F meterTrack = D2D1::RectF(rect.left + 8.0f * scale, rect.bottom - 6.0f * scale, rect.right - 8.0f * scale, rect.bottom - 4.0f * scale);
        chipBorder->SetOpacity(0.12f * settingsOpacity_);
        target_->FillRoundedRectangle(D2D1::RoundedRect(meterTrack, 1.0f * scale, 1.0f * scale), chipBorder.Get());
        
        D2D1_RECT_F meterFill = D2D1::RectF(meterTrack.left, meterTrack.top,
                                           meterTrack.left + (meterTrack.right - meterTrack.left) * clamped,
                                           meterTrack.bottom);
        metricBrush->SetOpacity(0.85f);
        target_->FillRoundedRectangle(D2D1::RoundedRect(meterFill, 1.0f * scale, 1.0f * scale), metricBrush.Get());
        
        textBrush_->SetOpacity(0.90f);
        mutedBrush_->SetOpacity(0.58f);
    }

    void DrawMedia(const SharedState& state, D2D1_RECT_F rect, double now) {
        Settings settings = GetSettingsSnapshot();
        const float height = rect.bottom - rect.top;

        float radius = CalculateCornerRadius(height, settings);
        ComPtr<ID2D1RoundedRectangleGeometry> mask;
        d2dFactory_->CreateRoundedRectangleGeometry(D2D1::RoundedRect(rect, radius, radius), &mask);
        ComPtr<ID2D1Layer> layer;
        target_->CreateLayer(&layer);

        float expandedAlpha = std::clamp((height - 60.0f) / 60.0f, 0.0f, 1.0f);
        float collapsedAlpha = std::clamp((80.0f - height) / 30.0f, 0.0f, 1.0f);

        // Expanded UI
        if (expandedAlpha > 0.01f && mask && layer) {
            target_->PushLayer(D2D1::LayerParameters(rect, mask.Get(), D2D1_ANTIALIAS_MODE_PER_PRIMITIVE, D2D1::IdentityMatrix(), expandedAlpha, nullptr, D2D1_LAYER_OPTIONS_NONE), layer.Get());
            
            int tab = Modulo(g_idleTab.load(), 3);

            if (tab == 0) {
                const float artSize = 64.0f;
                D2D1_RECT_F artRect = D2D1::RectF(rect.left + 24.0f, rect.top + 20.0f,
                                                  rect.left + 24.0f + artSize, rect.top + 20.0f + artSize);
                DrawAlbumArt(state.media, artRect, now, 16.0f, true);

                float shiftX = 0.0f;
                if (state.system.micActive && state.system.cameraActive) shiftX = 30.0f;
                else if (state.system.micActive || state.system.cameraActive) shiftX = 16.0f;

                const float waveW = 32.0f;
                const float waveH = 20.0f;
                D2D1_RECT_F waveRect = D2D1::RectF(rect.right - 24.0f - shiftX - waveW,
                                                   rect.top + 20.0f + (artSize - waveH) * 0.5f,
                                                   rect.right - 24.0f - shiftX,
                                                   rect.top + 20.0f + (artSize + waveH) * 0.5f);

                const float textLeft = artRect.right + 18.0f;
                const float textRight = waveRect.left - 16.0f;
                
                D2D1_RECT_F titleRect = D2D1::RectF(textLeft, rect.top + 34.0f, textRight, rect.top + 54.0f);
                DrawMarqueeText(state.media.title.empty() ? L"Unknown" : state.media.title,
                                titleRect, textFormat_.Get(), textBrush_.Get(), now, 42.0f);

                D2D1_RECT_F artistRect = D2D1::RectF(textLeft, rect.top + 54.0f, textRight, rect.top + 74.0f);
                mutedBrush_->SetOpacity(0.55f);
                DrawMarqueeText(state.media.artist.empty() ? L"" : state.media.artist,
                                artistRect, smallTextFormat_.Get(), mutedBrush_.Get(), now, 30.0f);
                mutedBrush_->SetOpacity(0.50f);

                if (state.media.playing) {
                    DrawWaveform(state, waveRect, settings);
                } else {
                    mutedBrush_->SetOpacity(0.5f);
                    for (int i = 0; i < 4; ++i) {
                        target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(waveRect.left + i * 4.0f + 2.0f, (waveRect.top + waveRect.bottom) * 0.5f), 1.2f, 1.2f), mutedBrush_.Get());
                    }
                }

                // Timeline Scrubber
                const float scrubberY = rect.top + 114.0f;
                double currentPosition = state.media.positionTicks / 10000000.0;
                double duration = state.media.endTicks / 10000000.0;
                if (state.media.playing && state.media.lastUpdatedTicks > 0) {
                    currentPosition += (GetTickCount64() - state.media.lastUpdatedTicks) / 1000.0;
                }
                currentPosition = std::max(0.0, std::min(currentPosition, duration));

                auto FormatTime = [](double seconds) -> std::wstring {
                    if (seconds <= 0.0 || _isnan(seconds)) return L"0:00";
                    int m = static_cast<int>(seconds) / 60;
                    int s = static_cast<int>(seconds) % 60;
                    wchar_t buf[16];
                    swprintf_s(buf, L"%d:%02d", m, s);
                    return buf;
                };

                std::wstring elapsedStr = FormatTime(currentPosition);
                std::wstring remainStr = L"-" + FormatTime(duration - currentPosition);

                const float scrubLeft = rect.left + 24.0f;
                const float scrubRight = rect.right - 24.0f;
                
                mutedBrush_->SetOpacity(0.8f);
                D2D1_RECT_F elRect = D2D1::RectF(scrubLeft, scrubberY - 8.0f, scrubLeft + 40.0f, scrubberY + 8.0f);
                target_->DrawTextW(elapsedStr.c_str(), static_cast<UINT32>(elapsedStr.size()), smallTextFormat_.Get(), elRect, mutedBrush_.Get());
                
                D2D1_RECT_F remRect = D2D1::RectF(scrubRight - 36.0f, scrubberY - 8.0f, scrubRight, scrubberY + 8.0f);
                target_->DrawTextW(remainStr.c_str(), static_cast<UINT32>(remainStr.size()), smallTextFormat_.Get(), remRect, mutedBrush_.Get());

                const float barLeft = scrubLeft + 36.0f;
                const float barRight = scrubRight - 38.0f;
                const float progress = duration > 0.0 ? static_cast<float>(currentPosition / duration) : 0.0f;

                ComPtr<ID2D1SolidColorBrush> scrubBg;
                target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.15f), &scrubBg);
                target_->FillRoundedRectangle(D2D1::RoundedRect(D2D1::RectF(barLeft, scrubberY - 2.5f, barRight, scrubberY + 2.5f), 2.5f, 2.5f), scrubBg.Get());

                ComPtr<ID2D1SolidColorBrush> scrubFg;
                target_->CreateSolidColorBrush(state.media.art.bgra.empty() ? D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.9f) : state.media.art.sampledAccent, &scrubFg);
                const float scrubW = (barRight - barLeft) * progress;
                target_->FillRoundedRectangle(D2D1::RoundedRect(D2D1::RectF(barLeft, scrubberY - 2.5f, barLeft + scrubW, scrubberY + 2.5f), 2.5f, 2.5f), scrubFg.Get());

                // Controls
                const float cy = rect.top + 148.0f;
                const float cx = (rect.left + rect.right) * 0.5f;
                DrawMediaControls(state.media.playing, 
                                  D2D1::Point2F(cx - 64.0f, cy),
                                  D2D1::Point2F(cx, cy),
                                  D2D1::Point2F(cx + 64.0f, cy));
            } else if (tab == 1) {
                SYSTEMTIME local = {}; GetLocalTime(&local);
                DrawCalendarDashboard(state, rect, settings, now, 1.0f, local);
            } else if (tab == 2) {
                bool hasWeather = state.weather.hasData && (now - state.weather.lastUpdated < 3600.0);
                std::wstring wIcon = L"🌡️"; std::wstring wText = L"Loading...";
                if (hasWeather) {
                    wText = state.weather.weatherDesc;
                    GetWeatherIconAndText(state.weather.weatherCode, wIcon, wText);
                }
                DrawWeatherDashboard(state, rect, settings, now, 1.0f, hasWeather, wIcon, wText);
            }

            // Pagination dots
            const float scale = 1.0f;
            float shiftX = 0.0f;
            if (state.system.micActive && state.system.cameraActive) shiftX = 30.0f * scale;
            else if (state.system.micActive || state.system.cameraActive) shiftX = 16.0f * scale;

            const float dotX = rect.right - 10.0f * scale - shiftX;
            const float dotY = (rect.top + rect.bottom) * 0.5f;
            const float spacing = 8.0f * scale;
            const float r = settings.paginationDotSize * scale;
            
            ComPtr<ID2D1SolidColorBrush> activeDot, inactiveDot;
            target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.85f * settingsOpacity_), &activeDot);
            target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.25f * settingsOpacity_), &inactiveDot);

            target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(dotX, dotY - spacing), r, r), tab == 0 ? activeDot.Get() : inactiveDot.Get());
            target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(dotX, dotY), r, r), tab == 1 ? activeDot.Get() : inactiveDot.Get());
            target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(dotX, dotY + spacing), r, r), tab == 2 ? activeDot.Get() : inactiveDot.Get());

            target_->PopLayer();
        }

        // Collapsed UI
        if (collapsedAlpha > 0.01f && mask && layer) {
            target_->PushLayer(D2D1::LayerParameters(rect, mask.Get(), D2D1_ANTIALIAS_MODE_PER_PRIMITIVE, D2D1::IdentityMatrix(), collapsedAlpha, nullptr, D2D1_LAYER_OPTIONS_NONE), layer.Get());
            
            const float cy = (rect.top + rect.bottom) * 0.5f;
            const float artPadding = 6.0f;
            const float artSize = height - artPadding * 2.0f;
            
            D2D1_RECT_F artRect = D2D1::RectF(rect.left + 8.0f, cy - artSize * 0.5f,
                                              rect.left + 8.0f + artSize, cy + artSize * 0.5f);
            DrawAlbumArt(state.media, artRect, now, artSize * 0.5f, false);

            float shiftX = 0.0f;
            if (state.system.micActive && state.system.cameraActive) shiftX = 30.0f;
            else if (state.system.micActive || state.system.cameraActive) shiftX = 16.0f;

            D2D1_RECT_F waveRect = D2D1::RectF(rect.right - 42.0f - shiftX, cy - 10.0f,
                                               rect.right - 14.0f - shiftX, cy + 10.0f);
            if (state.media.playing) {
                DrawWaveform(state, waveRect, settings);
            } else {
                mutedBrush_->SetOpacity(0.5f);
                for (int i = 0; i < 4; ++i) {
                    target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(waveRect.left + i * 6.0f + 3.0f, cy), 1.5f, 1.5f), mutedBrush_.Get());
                }
            }

            target_->PopLayer();
        }
    }

    void DrawMediaControls(bool playing, D2D1_POINT_2F prev, D2D1_POINT_2F play, D2D1_POINT_2F next) {
        DrawMediaButton(prev, 16.0f, 0, false);
        DrawMediaButton(play, 22.0f, playing ? 1 : 2, true);
        DrawMediaButton(next, 16.0f, 3, false);
    }

    void DrawMediaButton(D2D1_POINT_2F center, float radius, int kind, bool primary) {
        int buttonCmd = (kind == 0) ? 0 : ((kind == 1 || kind == 2) ? 1 : 2);
        bool isPressed = (g_pressedMediaButton.load() == buttonCmd);

        if (isPressed) radius *= 0.88f;

        ComPtr<ID2D1SolidColorBrush> bg;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, primary ? (isPressed ? 0.16f : 0.080f) : (isPressed ? 0.10f : 0.040f)), &bg);
        target_->FillEllipse(D2D1::Ellipse(center, radius, radius), bg.Get());
        accentBrush_->SetOpacity(primary ? (isPressed ? 1.0f : 0.88f) : (isPressed ? 0.80f : 0.62f));

        if (kind == 1) {  // pause
            const float h = radius * 0.72f;
            target_->FillRoundedRectangle(D2D1::RoundedRect(
                                             D2D1::RectF(center.x - 4.0f, center.y - h * 0.5f,
                                                         center.x - 1.5f, center.y + h * 0.5f),
                                             1.0f, 1.0f),
                                         accentBrush_.Get());
            target_->FillRoundedRectangle(D2D1::RoundedRect(
                                             D2D1::RectF(center.x + 1.5f, center.y - h * 0.5f,
                                                         center.x + 4.0f, center.y + h * 0.5f),
                                             1.0f, 1.0f),
                                         accentBrush_.Get());
        } else {
            const float dir = kind == 0 ? -1.0f : 1.0f;
            const float tri = radius * (primary ? 0.70f : 0.62f);
            const float cx = (kind == 0 || kind == 3) ? center.x - dir * radius * 0.16f : center.x;

            D2D1_POINT_2F p1 = D2D1::Point2F(cx - dir * tri * 0.35f, center.y - tri * 0.58f);
            D2D1_POINT_2F p2 = D2D1::Point2F(cx - dir * tri * 0.35f, center.y + tri * 0.58f);
            D2D1_POINT_2F p3 = D2D1::Point2F(cx + dir * tri * 0.55f, center.y);
            ComPtr<ID2D1PathGeometry> geom;
            d2dFactory_->CreatePathGeometry(&geom);
            ComPtr<ID2D1GeometrySink> sink;
            if (SUCCEEDED(geom->Open(&sink))) {
                sink->BeginFigure(p1, D2D1_FIGURE_BEGIN_FILLED);
                sink->AddLine(p2);
                sink->AddLine(p3);
                sink->EndFigure(D2D1_FIGURE_END_CLOSED);
                sink->Close();
                target_->FillGeometry(geom.Get(), accentBrush_.Get());
            }

            if (kind == 0 || kind == 3) {
                const float x = cx + dir * radius * 0.55f;
                target_->DrawLine(D2D1::Point2F(x, center.y - radius * 0.45f),
                                  D2D1::Point2F(x, center.y + radius * 0.45f),
                                  accentBrush_.Get(), 1.5f);
            }
        }

        accentBrush_->SetOpacity(1.0f);
    }

    void DrawAlbumArt(const MediaSnapshot& media, D2D1_RECT_F rect, double now, float radius, bool drawBadge) {
        (void)now;
        ComPtr<ID2D1RoundedRectangleGeometry> mask;
        HRESULT hrMask = d2dFactory_->CreateRoundedRectangleGeometry(
            D2D1::RoundedRect(rect, radius, radius), &mask);
        ComPtr<ID2D1Layer> layer;
        HRESULT hrLayer = target_->CreateLayer(nullptr, &layer);
        const bool roundedClip = SUCCEEDED(hrMask) && SUCCEEDED(hrLayer) && mask && layer;
        if (roundedClip) {
            target_->PushLayer(D2D1::LayerParameters(rect, mask.Get()), layer.Get());
        } else {
            target_->PushAxisAlignedClip(rect, D2D1_ANTIALIAS_MODE_PER_PRIMITIVE);
        }

        if (!media.art.bgra.empty()) {
            if (artGeneration_ != media.art.generation || !artBitmap_) {
                D2D1_BITMAP_PROPERTIES props = D2D1::BitmapProperties(
                    D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED));
                target_->CreateBitmap(D2D1::SizeU(media.art.width, media.art.height),
                                      media.art.bgra.data(), media.art.width * 4,
                                      &props, &artBitmap_);
                artGeneration_ = media.art.generation;
            }

            D2D1_RECT_F dst = D2D1::RectF(rect.left, rect.top, rect.right, rect.bottom);
            if (artBitmap_) {
                target_->DrawBitmap(artBitmap_.Get(), dst, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
            }
        } else {
            accentBrush_->SetOpacity(0.24f);
            target_->FillRoundedRectangle(D2D1::RoundedRect(rect, radius, radius), accentBrush_.Get());
            accentBrush_->SetOpacity(1.0f);
            if (!media.sourceIcon.bgra.empty()) {
                D2D1_RECT_F iconRect = D2D1::RectF(rect.left + 11, rect.top + 11, rect.right - 11, rect.bottom - 11);
                DrawBitmapPixels(media.sourceIcon, iconRect, mediaSourceIconBitmap_, mediaSourceIconGeneration_, 0.95f);
            } else {
                target_->DrawTextW(media.sourceBadge.empty() ? L"\u25b6" : media.sourceBadge.c_str(),
                                   static_cast<UINT32>(media.sourceBadge.empty() ? 1 : media.sourceBadge.size()),
                                   textFormat_.Get(), rect, textBrush_.Get());
            }
        }

        if (drawBadge && !media.sourceIcon.bgra.empty()) {
            D2D1_RECT_F badge = D2D1::RectF(rect.right - 24, rect.bottom - 22, rect.right - 3, rect.bottom - 3);
            DrawCircularBitmapPixels(media.sourceIcon,
                                     D2D1::Point2F((badge.left + badge.right) * 0.5f, (badge.top + badge.bottom) * 0.5f),
                                     9.5f, mediaSourceIconBitmap_, mediaSourceIconGeneration_, 0.98f);
        }

        if (roundedClip) target_->PopLayer();
        else target_->PopAxisAlignedClip();
    }

    void DrawBitmapPixels(const BitmapPixels& pixels, D2D1_RECT_F rect,
                          ComPtr<ID2D1Bitmap>& cache, uint64_t& cachedGeneration,
                          float opacity = 1.0f) {
        if (pixels.bgra.empty()) return;

        if (cachedGeneration != pixels.generation || !cache) {
            D2D1_BITMAP_PROPERTIES props = D2D1::BitmapProperties(
                D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED));
            target_->CreateBitmap(D2D1::SizeU(pixels.width, pixels.height),
                                  pixels.bgra.data(), pixels.width * 4,
                                  &props, &cache);
            cachedGeneration = pixels.generation;
        }

        if (cache) {
            target_->DrawBitmap(cache.Get(), rect, opacity, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
        }
    }

    void DrawRoundedBitmapPixels(const BitmapPixels& pixels, D2D1_RECT_F badge,
                                 float cornerRadius,
                                 ComPtr<ID2D1Bitmap>& cache, uint64_t& cachedGeneration,
                                 float opacity = 1.0f) {
        if (pixels.bgra.empty()) return;

        const float pad = 2.0f;
        D2D1_RECT_F iconRect = D2D1::RectF(badge.left + pad, badge.top + pad, badge.right - pad, badge.bottom - pad);
        const float innerR = std::max(0.0f, cornerRadius - pad);

        ComPtr<ID2D1RoundedRectangleGeometry> mask;
        d2dFactory_->CreateRoundedRectangleGeometry(D2D1::RoundedRect(iconRect, innerR, innerR), &mask);
        ComPtr<ID2D1Layer> layer;
        target_->CreateLayer(nullptr, &layer);

        if (mask && layer) {
            target_->PushLayer(D2D1::LayerParameters(iconRect, mask.Get(), D2D1_ANTIALIAS_MODE_PER_PRIMITIVE), layer.Get());
            DrawBitmapPixels(pixels, iconRect, cache, cachedGeneration, opacity);
            target_->PopLayer();
        } else {
            DrawBitmapPixels(pixels, iconRect, cache, cachedGeneration, opacity);
        }
    }

    void DrawCircularBitmapPixels(const BitmapPixels& pixels, D2D1_POINT_2F center, float radius,
                                  ComPtr<ID2D1Bitmap>& cache, uint64_t& cachedGeneration,
                                  float opacity = 1.0f) {
        if (pixels.bgra.empty()) return;

        D2D1_RECT_F rect = D2D1::RectF(center.x - radius, center.y - radius, center.x + radius, center.y + radius);
        ComPtr<ID2D1EllipseGeometry> ellipse;
        d2dFactory_->CreateEllipseGeometry(D2D1::Ellipse(center, radius, radius), &ellipse);
        ComPtr<ID2D1Layer> layer;
        target_->CreateLayer(nullptr, &layer);

        if (ellipse && layer) {
            target_->PushLayer(D2D1::LayerParameters(rect, ellipse.Get(), D2D1_ANTIALIAS_MODE_PER_PRIMITIVE), layer.Get());
            DrawBitmapPixels(pixels, rect, cache, cachedGeneration, opacity);
            target_->PopLayer();
        } else {
            DrawBitmapPixels(pixels, rect, cache, cachedGeneration, opacity);
        }

        if (!glowBorderBrush_) target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.12f), &glowBorderBrush_);
        glowBorderBrush_->SetOpacity(0.12f);
        if (glowBorderBrush_) target_->DrawEllipse(D2D1::Ellipse(center, radius, radius), glowBorderBrush_.Get(), 1.0f);
    }

    void DrawMarqueeText(const std::wstring& text, D2D1_RECT_F rect, IDWriteTextFormat* format,
                         ID2D1Brush* brush, double now, float speed) {
        if (!format || !brush || text.empty()) return;

        const float layoutHeight = rect.bottom - rect.top;
        const bool layoutDirty = (text != cachedMarqueeText_ || std::abs(layoutHeight - cachedMarqueeHeight_) > 0.5f);
        if (layoutDirty || !cachedMarqueeLayout_) {
            cachedMarqueeText_ = text;
            cachedMarqueeHeight_ = layoutHeight;
            cachedMarqueeLayout_ = nullptr;
            dwriteFactory_->CreateTextLayout(text.c_str(), static_cast<UINT32>(text.size()),
                                             format, 2000.0f, layoutHeight, &cachedMarqueeLayout_);
        }
        ComPtr<IDWriteTextLayout> layout = cachedMarqueeLayout_;
        DWRITE_TEXT_METRICS metrics = {};
        if (layout) layout->GetMetrics(&metrics);

        const float available = rect.right - rect.left;
        D2D1_RECT_F clipRect = rect;
        clipRect.top -= 10.0f;
        clipRect.bottom += 10.0f;
        target_->PushAxisAlignedClip(clipRect, D2D1_ANTIALIAS_MODE_PER_PRIMITIVE);

        if (metrics.widthIncludingTrailingWhitespace <= available) {
            target_->DrawTextLayout(D2D1::Point2F(rect.left, rect.top), layout.Get(), brush, D2D1_DRAW_TEXT_OPTIONS_NONE);
        } else {
            const float cycle = metrics.widthIncludingTrailingWhitespace + 38.0f;
            const float offset = std::fmod(static_cast<float>(now) * speed, cycle);
            target_->DrawTextLayout(D2D1::Point2F(rect.left - offset, rect.top), layout.Get(), brush, D2D1_DRAW_TEXT_OPTIONS_NONE);
            target_->DrawTextLayout(D2D1::Point2F(rect.left - offset + cycle, rect.top), layout.Get(), brush, D2D1_DRAW_TEXT_OPTIONS_NONE);
        }
        target_->PopAxisAlignedClip();
    }

    void DrawWaveform(const SharedState& state, D2D1_RECT_F rect, const Settings& settings) {
        const float gap = settings.waveformGapPx;
        const float minBarWidth = 2.0f;
        const float availableW = rect.right - rect.left;
        size_t targetCount = static_cast<size_t>(ClampInt(settings.waveformBarCount, 8, 32));
        size_t count = std::max<size_t>(1, static_cast<size_t>((availableW + gap) / (minBarWidth + gap)));
        count = std::min<size_t>(count, targetCount);

        const float barWidth = (availableW - gap * (count - 1)) / count;
        const float centerY = (rect.top + rect.bottom) * 0.5f;
        const float maxH = (rect.bottom - rect.top) * 0.86f;
        const size_t step = 4;

        for (size_t i = 0; i < count; ++i) {
            const size_t offset = (count - i) * step;
            const size_t source = (state.waveformWrite + state.waveform.size() - offset) % state.waveform.size();
            const float amp = Clamp(state.waveform[source], 0.03f, 1.0f);
            const float h = std::max(3.0f, amp * maxH);
            const float x = rect.left + i * (barWidth + gap);

            const float t = (count > 1) ? static_cast<float>(i) / static_cast<float>(count - 1) : 0.0f;
            const float freqBlend = t * 0.7f;
            D2D1::ColorF accentCol(0.42f, 0.79f, 0.94f);
            D2D1::ColorF barColor(
                Lerp(accentCol.r, 1.0f, freqBlend),
                Lerp(accentCol.g, 1.0f, freqBlend),
                Lerp(accentCol.b, 1.0f, freqBlend),
                0.45f + 0.5f * amp);

            D2D1_RECT_F bar = D2D1::RectF(x, centerY - h * 0.5f, x + barWidth, centerY + h * 0.5f);
            accentBrush_->SetColor(barColor);
            target_->FillRoundedRectangle(D2D1::RoundedRect(bar, barWidth * 0.5f, barWidth * 0.5f), accentBrush_.Get());
        }
        accentBrush_->SetOpacity(1.0f);
    }

    void DrawClipboard(const SharedState& state, D2D1_RECT_F rect) {
        if (rect.bottom - rect.top < 40.0f || rect.right - rect.left < 100.0f) return;
        const double now = NowSeconds();
        const float ttl = 2.5f;
        const float remaining = Clamp(static_cast<float>(state.clipboard.expiresAt - now), 0.0f, ttl);
        const float progress = remaining / ttl;

        D2D1_RECT_F badge = D2D1::RectF(rect.left + 12, rect.top + 10, rect.left + 50, rect.bottom - 10);
        ComPtr<ID2D1SolidColorBrush> badgeBg;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.070f), &badgeBg);
        target_->FillRoundedRectangle(D2D1::RoundedRect(badge, 13, 13), badgeBg.Get());
        target_->DrawRoundedRectangle(D2D1::RoundedRect(badge, 13, 13), accentBrush_.Get(), 1.0f);

        if (!state.clipboard.appIcon.bgra.empty()) {
            DrawRoundedBitmapPixels(state.clipboard.appIcon, badge, 10.0f, clipboardIconBitmap_, clipboardIconGeneration_, 0.96f);
        } else {
            const wchar_t* glyph = state.clipboard.image ? L"\uE114" : L"\uE8C8";
            ComPtr<ID2D1SolidColorBrush> iconBg;
            const D2D1_COLOR_F iconColor = state.clipboard.image
                ? D2D1::ColorF(0.3f, 0.3f, 0.35f, 0.90f)
                : D2D1::ColorF(1, 1, 1, 0.055f * settingsOpacity_);
            target_->CreateSolidColorBrush(iconColor, &iconBg);
            target_->FillRoundedRectangle(D2D1::RoundedRect(badge, 13, 13), iconBg.Get());
            textBrush_->SetOpacity(0.95f);
            
            if (iconFormat_) {
                iconFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
                iconFormat_->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
                target_->DrawTextW(glyph, static_cast<UINT32>(wcslen(glyph)), iconFormat_.Get(), badge, textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_CLIP);
                iconFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
                iconFormat_->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);
            }
            textBrush_->SetOpacity(0.90f);
        }

        D2D1_RECT_F titleRect = D2D1::RectF(badge.right + 11, rect.top + 9, rect.right - 18, rect.top + 25);
        mutedBrush_->SetOpacity(0.48f);
        const std::wstring clipTitle = state.clipboard.appName.empty()
            ? (state.clipboard.image ? std::wstring(L"Image copied") : std::wstring(L"Clipboard"))
            : state.clipboard.appName + L"  \u00b7  Clipboard";
        target_->DrawTextW(clipTitle.c_str(), static_cast<UINT32>(clipTitle.size()), smallTextFormat_.Get(), titleRect, mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_CLIP);

        D2D1_RECT_F textRect = D2D1::RectF(badge.right + 11, rect.top + 25, rect.right - 18, rect.bottom - 12);
        DrawMarqueeText(state.clipboard.text.empty() ? L"Copied" : state.clipboard.text, textRect, textFormat_.Get(), textBrush_.Get(), now, 34.0f);

        D2D1_RECT_F track = D2D1::RectF(badge.right + 11, rect.bottom - 8, rect.right - 20, rect.bottom - 6);
        ComPtr<ID2D1SolidColorBrush> trackBrush;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.08f), &trackBrush);
        target_->FillRoundedRectangle(D2D1::RoundedRect(track, 1, 1), trackBrush.Get());
        D2D1_RECT_F fill = D2D1::RectF(track.left, track.top, track.left + (track.right - track.left) * progress, track.bottom);
        accentBrush_->SetOpacity(0.55f);
        target_->FillRoundedRectangle(D2D1::RoundedRect(fill, 1, 1), accentBrush_.Get());
        accentBrush_->SetOpacity(1.0f);
        mutedBrush_->SetOpacity(0.58f);
    }

    void DrawNotification(const SharedState& state, D2D1_RECT_F rect) {
        if (rect.bottom - rect.top < 48.0f || rect.right - rect.left < 120.0f) return;
        const double now = NowSeconds();
        const float ttl = 4.0f;
        const float remaining = Clamp(static_cast<float>(state.notification.expiresAt - now), 0.0f, ttl);
        const float progress = remaining / ttl;

        const float cy = (rect.top + rect.bottom) * 0.5f;
        const float iconSz = (rect.bottom - rect.top) - 16.0f;
        D2D1_RECT_F badge = D2D1::RectF(rect.left + 14, cy - iconSz * 0.5f, rect.left + 14 + iconSz, cy + iconSz * 0.5f);
        const float br = iconSz * 0.35f;

        ComPtr<ID2D1SolidColorBrush> plateBrush;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.12f), &plateBrush);
        target_->FillRoundedRectangle(D2D1::RoundedRect(badge, br, br), plateBrush.Get());

        if (!state.notification.icon.bgra.empty()) {
            DrawRoundedBitmapPixels(state.notification.icon, badge, br, notificationIconBitmap_, notificationIconGeneration_, 1.0f);

            ComPtr<ID2D1SolidColorBrush> badgeColor;
            target_->CreateSolidColorBrush(D2D1::ColorF(1.0f, 0.23f, 0.18f, 1.0f), &badgeColor);
            const float dotR = iconSz * 0.13f;
            const float dotX = badge.right - dotR * 0.5f;
            const float dotY = badge.top + dotR * 0.5f;
            target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(dotX, dotY), dotR, dotR), badgeColor.Get());

            ComPtr<ID2D1SolidColorBrush> badgeBorder;
            target_->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.95f), &badgeBorder);
            target_->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(dotX, dotY), dotR, dotR), badgeBorder.Get(), 0.9f);
        }

        const float tx = badge.right + 14;
        D2D1_RECT_F appRect = D2D1::RectF(tx, cy - 22, rect.right - 14, cy - 6);
        mutedBrush_->SetOpacity(0.50f);
        target_->DrawTextW(state.notification.app.c_str(), static_cast<UINT32>(state.notification.app.size()), smallTextFormat_.Get(), appRect, mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_CLIP);

        D2D1_RECT_F titleRect = D2D1::RectF(tx, cy - 4, rect.right - 14, cy + 17);
        textBrush_->SetOpacity(0.95f);
        DrawMarqueeText(state.notification.title.empty() ? L"Notification" : state.notification.title, titleRect, textFormat_.Get(), textBrush_.Get(), now, 28.0f);
        textBrush_->SetOpacity(0.90f);

        D2D1_RECT_F track = D2D1::RectF(tx, rect.bottom - 7, rect.right - 14, rect.bottom - 3);
        ComPtr<ID2D1SolidColorBrush> trackBrush;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.08f), &trackBrush);
        target_->FillRoundedRectangle(D2D1::RoundedRect(track, 2, 2), trackBrush.Get());
        D2D1_RECT_F fill = D2D1::RectF(track.left, track.top, track.left + (track.right - track.left) * progress, track.bottom);
        accentBrush_->SetOpacity(0.75f);
        target_->FillRoundedRectangle(D2D1::RoundedRect(fill, 2, 2), accentBrush_.Get());
        accentBrush_->SetOpacity(1.0f);
        mutedBrush_->SetOpacity(0.50f);
    }

    void DrawVolume(const SharedState& state, D2D1_RECT_F rect) {
        if (rect.bottom - rect.top < 24.0f || rect.right - rect.left < 140.0f) return;
        const bool muted = state.volume.muted || state.volume.percent == 0;
        const float cy = (rect.top + rect.bottom) * 0.5f;
        const float badgeSz = (rect.bottom - rect.top) - 16.0f;
        D2D1_RECT_F badge = D2D1::RectF(rect.left + 14, cy - badgeSz * 0.5f, rect.left + 14 + badgeSz, cy + badgeSz * 0.5f);
        const float br = badgeSz * 0.35f;

        ComPtr<ID2D1SolidColorBrush> badgeBg;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.12f), &badgeBg);
        target_->FillRoundedRectangle(D2D1::RoundedRect(badge, br, br), badgeBg.Get());

        const wchar_t* glyph = muted ? L"\uE74F" : L"\uE993";
        textBrush_->SetOpacity(0.95f);
        if (iconFormat_) {
            iconFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
            iconFormat_->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
            target_->DrawTextW(glyph, static_cast<UINT32>(wcslen(glyph)), iconFormat_.Get(), badge, textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_CLIP);
            iconFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
            iconFormat_->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);
        }

        const float tx = badge.right + 14;
        D2D1_RECT_F labelRect = D2D1::RectF(tx, cy - 22, rect.right - 58, cy - 6);
        mutedBrush_->SetOpacity(0.50f);
        const std::wstring deviceLabel = state.volume.deviceName.empty() ? std::wstring(L"Volume") : state.volume.deviceName;
        target_->DrawTextW(deviceLabel.c_str(), static_cast<UINT32>(deviceLabel.size()), smallTextFormat_.Get(), labelRect, mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_CLIP);

        wchar_t value[16] = {};
        if (muted) wcscpy_s(value, ARRAYSIZE(value), L"Muted");
        else swprintf_s(value, L"%d%%", state.volume.percent);
        D2D1_RECT_F valueRect = D2D1::RectF(rect.right - 58, cy - 22, rect.right - 14, cy - 6);
        target_->DrawTextW(value, static_cast<UINT32>(wcslen(value)), smallTextFormat_.Get(), valueRect, textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_CLIP);
        textBrush_->SetOpacity(0.90f);

        D2D1_RECT_F track = D2D1::RectF(tx, cy + 2, rect.right - 14, cy + 6);
        ComPtr<ID2D1SolidColorBrush> trackBrush;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.08f), &trackBrush);
        target_->FillRoundedRectangle(D2D1::RoundedRect(track, 2, 2), trackBrush.Get());
        const float pct = Clamp(state.volume.percent / 100.0f, 0.0f, 1.0f);
        D2D1_RECT_F fill = D2D1::RectF(track.left, track.top, track.left + (track.right - track.left) * pct, track.bottom);
        accentBrush_->SetOpacity(muted ? 0.24f : 0.85f);
        target_->FillRoundedRectangle(D2D1::RoundedRect(fill, 2, 2), accentBrush_.Get());
        accentBrush_->SetOpacity(1.0f);
        mutedBrush_->SetOpacity(0.58f);
    }

    void DrawCapsLock(const SharedState& state, D2D1_RECT_F rect) {
        if (rect.bottom - rect.top < 24.0f || rect.right - rect.left < 110.0f) return;
        const float cy = (rect.top + rect.bottom) * 0.5f;
        const float badgeSz = (rect.bottom - rect.top) - 16.0f;
        D2D1_RECT_F badge = D2D1::RectF(rect.left + 14, cy - badgeSz * 0.5f, rect.left + 14 + badgeSz, cy + badgeSz * 0.5f);
        const float br = badgeSz * 0.35f;

        ComPtr<ID2D1SolidColorBrush> badgeBg, badgeBorder;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.08f), &badgeBg);
        target_->FillRoundedRectangle(D2D1::RoundedRect(badge, br, br), badgeBg.Get());
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.16f), &badgeBorder);
        target_->DrawRoundedRectangle(D2D1::RoundedRect(badge, br, br), badgeBorder.Get(), 1.0f);

        const wchar_t* glyph = state.capsLock.isNumEvent ? L"1" : L"A";
        std::wstring label = state.capsLock.isNumEvent ? L"Num Lock" : L"Caps Lock";
        bool isOn = state.capsLock.isNumEvent ? state.capsLock.numOn : state.capsLock.capsOn;

        textBrush_->SetOpacity(0.95f);
        target_->DrawTextW(glyph, static_cast<UINT32>(wcslen(glyph)), clockFormat_.Get(), badge, textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_CLIP);

        ComPtr<ID2D1SolidColorBrush> ledBrush;
        D2D1_COLOR_F ledColor = isOn ? D2D1::ColorF(0.19f, 0.83f, 0.38f, 1.0f) : D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.22f);
        target_->CreateSolidColorBrush(ledColor, &ledBrush);
        D2D1_POINT_2F ledCenter = D2D1::Point2F(badge.right - 5.0f, badge.bottom - 5.0f);
        target_->FillEllipse(D2D1::Ellipse(ledCenter, 3.0f, 3.0f), ledBrush.Get());

        const float tx = badge.right + 14;
        D2D1_RECT_F labelRect = D2D1::RectF(tx, cy - 10, rect.right - 40, cy + 10);
        target_->DrawTextW(label.c_str(), static_cast<UINT32>(label.size()), smallTextFormat_.Get(), labelRect, textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_CLIP);

        std::wstring status = isOn ? L"ON" : L"OFF";
        D2D1_RECT_F statusRect = D2D1::RectF(rect.right - 40, cy - 10, rect.right - 14, cy + 10);
        mutedBrush_->SetOpacity(0.80f);
        target_->DrawTextW(status.c_str(), static_cast<UINT32>(status.size()), smallTextFormat_.Get(), statusRect, mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_CLIP);
    }

    void DrawDevice(const SharedState& state, D2D1_RECT_F rect) {
        if (rect.bottom - rect.top < 24.0f || rect.right - rect.left < 100.0f) return;
        const float cy = (rect.top + rect.bottom) * 0.5f;
        const bool connected = (state.device.eventType == DeviceEventType::Connected);
        const float badgeSz = (rect.bottom - rect.top) - 16.0f;
        D2D1_RECT_F badge = D2D1::RectF(rect.left + 14, cy - badgeSz * 0.5f, rect.left + 14 + badgeSz, cy + badgeSz * 0.5f);
        const float br = badgeSz * 0.35f;

        ComPtr<ID2D1SolidColorBrush> badgeBg;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.10f), &badgeBg);
        target_->FillRoundedRectangle(D2D1::RoundedRect(badge, br, br), badgeBg.Get());

        ComPtr<ID2D1SolidColorBrush> dotBrush;
        D2D1_COLOR_F dotColor = connected ? D2D1::ColorF(0.19f, 0.83f, 0.38f, 1.0f) : D2D1::ColorF(1.0f, 0.27f, 0.22f, 1.0f);
        target_->CreateSolidColorBrush(dotColor, &dotBrush);

        D2D1_POINT_2F dotCenter = D2D1::Point2F(badge.right - 4.5f, badge.bottom - 4.5f);
        target_->FillEllipse(D2D1::Ellipse(dotCenter, 4.5f, 4.5f), dotBrush.Get());

        const float tx = badge.right + 14;
        mutedBrush_->SetOpacity(0.50f);
        std::wstring label = connected ? L"Device Connected" : L"Device Removed";
        D2D1_RECT_F labelRect = D2D1::RectF(tx, cy - 22, rect.right - 14, cy - 5);
        target_->DrawTextW(label.c_str(), static_cast<UINT32>(label.size()), smallTextFormat_.Get(), labelRect, mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_CLIP);

        textBrush_->SetOpacity(0.95f);
        const std::wstring& name = state.device.deviceName.empty()
            ? (state.device.isBluetoothLike ? std::wstring(L"Bluetooth") : std::wstring(L"USB Device"))
            : state.device.deviceName;
        D2D1_RECT_F nameRect = D2D1::RectF(tx, cy - 3, rect.right - 14, cy + 17);
        target_->DrawTextW(name.c_str(), static_cast<UINT32>(name.size()), textFormat_.Get(), nameRect, textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_CLIP);
        textBrush_->SetOpacity(0.90f);
        mutedBrush_->SetOpacity(0.58f);
    }

    void DrawBattery(const SharedState& state, D2D1_RECT_F rect) {
        if (rect.bottom - rect.top < 24.0f || rect.right - rect.left < 140.0f) return;
        const float cy = (rect.top + rect.bottom) * 0.5f;
        const float badgeSz = (rect.bottom - rect.top) - 16.0f;
        D2D1_RECT_F badge = D2D1::RectF(rect.left + 14, cy - badgeSz * 0.5f, rect.left + 14 + badgeSz, cy + badgeSz * 0.5f);
        const float br = badgeSz * 0.35f;

        ComPtr<ID2D1SolidColorBrush> badgeBg;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.12f), &badgeBg);
        target_->FillRoundedRectangle(D2D1::RoundedRect(badge, br, br), badgeBg.Get());

        const float bx = badge.left + badgeSz * 0.25f;
        const float by = cy - badgeSz * 0.22f;
        const float bw = badgeSz * 0.45f;
        const float bh = badgeSz * 0.44f;
        D2D1_RECT_F batRect = D2D1::RectF(bx, by, bx + bw, by + bh);
        
        ComPtr<ID2D1SolidColorBrush> batBorder;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.85f), &batBorder);
        target_->DrawRoundedRectangle(D2D1::RoundedRect(batRect, 2, 2), batBorder.Get(), 1.5f);
        
        D2D1_RECT_F nubRect = D2D1::RectF(batRect.right, cy - 3, batRect.right + 2.5f, cy + 3);
        target_->FillRectangle(nubRect, batBorder.Get());

        const float pct = Clamp(state.battery.percent / 100.0f, 0.0f, 1.0f);
        D2D1_RECT_F fillRect = D2D1::RectF(batRect.left + 2, batRect.top + 2, batRect.left + 2 + (bw - 4) * pct, batRect.bottom - 2);
        
        ComPtr<ID2D1SolidColorBrush> batFill;
        if (state.battery.low) target_->CreateSolidColorBrush(D2D1::ColorF(1.0f, 0.23f, 0.18f, 1.0f), &batFill);
        else if (state.battery.charging) target_->CreateSolidColorBrush(D2D1::ColorF(0.19f, 0.83f, 0.38f, 1.0f), &batFill);
        else target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.95f), &batFill);
        target_->FillRoundedRectangle(D2D1::RoundedRect(fillRect, 1, 1), batFill.Get());

        const float tx = badge.right + 14;
        D2D1_RECT_F labelRect = D2D1::RectF(tx, cy - 22, rect.right - 14, cy - 6);
        mutedBrush_->SetOpacity(0.50f);
        std::wstring label = state.battery.charging ? L"Power Connected" : L"Battery Alert";
        target_->DrawTextW(label.c_str(), static_cast<UINT32>(label.size()), smallTextFormat_.Get(), labelRect, mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_CLIP);

        wchar_t value[128] = {};
        if (state.battery.secondsRemaining != BATTERY_LIFE_UNKNOWN && !state.battery.charging) {
            const DWORD minutes = state.battery.secondsRemaining / 60;
            swprintf_s(value, ARRAYSIZE(value), L"%d%% \u2022 %luh %02lum left", state.battery.percent, minutes / 60, minutes % 60);
        } else {
            swprintf_s(value, ARRAYSIZE(value), L"%d%%", state.battery.percent);
        }

        D2D1_RECT_F valueRect = D2D1::RectF(tx, cy - 4, rect.right - 14, cy + 17);
        textBrush_->SetOpacity(0.95f);
        target_->DrawTextW(value, static_cast<UINT32>(wcslen(value)), textFormat_.Get(), valueRect, textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_CLIP);
        textBrush_->SetOpacity(0.90f);
    }

    void DrawProgress(const SharedState& state, D2D1_RECT_F rect) {
        wchar_t buffer[64] = {};
        swprintf_s(buffer, L"Progress %d%%", state.progress.percent);
        target_->DrawTextW(buffer, static_cast<UINT32>(wcslen(buffer)), textFormat_.Get(),
                           D2D1::RectF(rect.left + 18, rect.top + 14, rect.right - 18, rect.bottom - 10),
                           textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_CLIP);
    }

    void DrawProgressRing(D2D1_RECT_F rect, int percent, const Settings& settings) {
        if (!target_ || !d2dFactory_) return;

        const float cx = (rect.left + rect.right) * 0.5f;
        const float cy = (rect.top + rect.bottom) * 0.5f;
        const float rx = (rect.right - rect.left) * 0.5f + 4.0f;
        const float ry = (rect.bottom - rect.top) * 0.5f + 4.0f;

        ComPtr<ID2D1SolidColorBrush> trackBrush;
        target_->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.12f * settingsOpacity_), &trackBrush);
        if (trackBrush) {
            target_->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(cx, cy), rx, ry), trackBrush.Get(), settings.progressRingThickness * 0.71f);
        }

        const float clampedPct = Clamp(percent / 100.0f, 0.0f, 1.0f);
        if (clampedPct <= 0.01f) return;

        ComPtr<ID2D1PathGeometry> geometry;
        if (FAILED(d2dFactory_->CreatePathGeometry(&geometry))) return;
        ComPtr<ID2D1GeometrySink> sink;
        if (FAILED(geometry->Open(&sink))) return;

        const float start = -3.14159265f * 0.5f;
        const float sweep = 2.0f * 3.14159265f * clampedPct;
        const int segments = std::max(6, static_cast<int>(64 * clampedPct));

        auto pointAt = [&](float a) {
            return D2D1::Point2F(cx + std::cos(a) * rx, cy + std::sin(a) * ry);
        };

        sink->BeginFigure(pointAt(start), D2D1_FIGURE_BEGIN_HOLLOW);
        for (int i = 1; i <= segments; ++i) {
            const float a = start + sweep * static_cast<float>(i) / segments;
            sink->AddLine(pointAt(a));
        }
        sink->EndFigure(D2D1_FIGURE_END_OPEN);
        sink->Close();

        accentBrush_->SetOpacity(0.95f * settingsOpacity_);
        target_->DrawGeometry(geometry.Get(), accentBrush_.Get(), settings.progressRingThickness);
        accentBrush_->SetOpacity(1.0f);
    }

    bool Render(const SharedState& state, const Settings& settings, const Activity& primary,
                const std::optional<Activity>& secondary, float width, float height,
                float nudge, bool hover, bool pinned, double now) {
        EnsureTextFormats(settings.sizeScale);
        const int pixelWidth = std::max(1, static_cast<int>(std::ceil(width + kRenderPadX * 2.0f)));
        const int pixelHeight = std::max(1, static_cast<int>(std::ceil(height + kRenderPadY * 2.0f)));

        if (pixelWidth != bitmapWidth_ || pixelHeight != bitmapHeight_) {
            if (!CreateBackingBitmap(pixelWidth, pixelHeight)) return false;
            PositionOverlayWindow(hwnd_, pixelWidth, pixelHeight);
        } else if (g_layoutDirty.exchange(false)) {
            PositionOverlayWindow(hwnd_, pixelWidth, pixelHeight);
        }

        RECT rc = {0, 0, bitmapWidth_, bitmapHeight_};
        HRESULT hr = target_->BindDC(memDc_, &rc);
        if (FAILED(hr)) return false;

        target_->BeginDraw();
        target_->Clear(D2D1::ColorF(0, 0.0f));

        EnsureBrushes(settings, state);
        settingsOpacity_ = settings.pillOpacity;

        const float hoverScale = hover || pinned ? settings.hoverScalePercent : 1.0f;
        const float scale = hoverScale;

        const float top = kRenderPadY + nudge;
        const float left = kRenderPadX;
        
        if (width >= 2.0f && height >= 2.0f) {
            if (secondary) {
                const float gap = settings.splitGap * settings.sizeScale;
                const float maxH = std::max(primary.height, secondary->height);
                const float pTop = top + (maxH - primary.height) * 0.5f;
                const float sTop = top + (maxH - secondary->height) * 0.5f;

                DrawPill(state, settings, primary,
                         D2D1::RectF(left, pTop, left + primary.width, pTop + primary.height),
                         scale, now);
                DrawPill(state, settings, *secondary,
                         D2D1::RectF(left + primary.width + gap, sTop,
                                      left + primary.width + gap + secondary->width,
                                      sTop + secondary->height),
                         scale, now);
            } else {
                DrawPill(state, settings, primary,
                         D2D1::RectF(left, top, left + width, top + height), scale, now);
            }
        }

        hr = target_->EndDraw();
        if (FAILED(hr)) return false;

        POINT src = {0, 0};
        SIZE size = {bitmapWidth_, bitmapHeight_};
        BLENDFUNCTION blend = {AC_SRC_OVER, 0, 255, AC_SRC_ALPHA};
        return UpdateLayeredWindow(hwnd_, nullptr, nullptr, &size, memDc_, &src, 0, &blend, ULW_ALPHA) != FALSE;
    }

   private:
    HWND hwnd_ = nullptr;
    HDC memDc_ = nullptr;
    HBITMAP memBitmap_ = nullptr;
    HGDIOBJ oldBitmap_ = nullptr;
    int bitmapWidth_ = 0;
    int bitmapHeight_ = 0;
    float settingsOpacity_ = 0.96f;

    ComPtr<ID2D1Factory> d2dFactory_;
    ComPtr<IDWriteFactory> dwriteFactory_;
    ComPtr<ID2D1DCRenderTarget> target_;

    ComPtr<ID2D1SolidColorBrush> pillBgBrush_;
    ComPtr<ID2D1SolidColorBrush> tintBrush_;
    ComPtr<ID2D1SolidColorBrush> accentBrush_;
    ComPtr<ID2D1SolidColorBrush> textBrush_;
    ComPtr<ID2D1SolidColorBrush> mutedBrush_;
    ComPtr<ID2D1SolidColorBrush> whiteBrush_;
    ComPtr<ID2D1SolidColorBrush> redBrush_;
    ComPtr<ID2D1SolidColorBrush> greenBrush_;
    ComPtr<ID2D1SolidColorBrush> yellowBrush_;
    ComPtr<ID2D1SolidColorBrush> cyanBrush_;
    ComPtr<ID2D1SolidColorBrush> orangeBrush_;
    ComPtr<ID2D1SolidColorBrush> glassBorderBrush_;
    ComPtr<ID2D1SolidColorBrush> glassGlossBrush_;
    ComPtr<ID2D1SolidColorBrush> shadowBrushes_[6];

    ComPtr<IDWriteTextFormat> textFormat_;
    ComPtr<IDWriteTextFormat> smallTextFormat_;
    ComPtr<IDWriteTextFormat> clockFormat_;
    ComPtr<IDWriteTextFormat> boldTextFormat_;
    ComPtr<IDWriteTextFormat> hugeTextFormat_;
    ComPtr<IDWriteTextFormat> iconFormat_;

    ComPtr<ID2D1Bitmap> artBitmap_;
    uint64_t artGeneration_ = 0;
    ComPtr<ID2D1Bitmap> mediaSourceIconBitmap_;
    uint64_t mediaSourceIconGeneration_ = 0;
    ComPtr<ID2D1Bitmap> notificationIconBitmap_;
    uint64_t notificationIconGeneration_ = 0;
    ComPtr<ID2D1Bitmap> clipboardIconBitmap_;
    uint64_t clipboardIconGeneration_ = 0;

    // Gradient brush cache — avoids per-frame StopCollection + Brush allocation
    ComPtr<ID2D1GradientStopCollection> sheenStops_;
    ComPtr<ID2D1LinearGradientBrush> sheenBrush_;
    float cachedSheenIntensity_ = -1.0f;
    float cachedSheenOpacity_ = -1.0f;

    ComPtr<ID2D1GradientStopCollection> shimmerStops_;
    ComPtr<ID2D1LinearGradientBrush> shimmerBrush_;
    float cachedShimmerIntensity_ = -1.0f;
    float cachedShimmerOpacity_ = -1.0f;

    ComPtr<ID2D1SolidColorBrush> glowBorderBrush_;

    // Text layout cache — avoids per-frame IDWriteTextLayout allocation for marquee
    std::wstring cachedMarqueeText_;
    float cachedMarqueeHeight_ = 0.0f;
    ComPtr<IDWriteTextLayout> cachedMarqueeLayout_;
};

LRESULT CALLBACK OverlayWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static bool tracking = false;
    static bool isDraggingScrubber = false;

    switch (msg) {
        case WM_MOUSEMOVE: {
            if (!tracking) {
                TRACKMOUSEEVENT tme = {sizeof(tme), TME_LEAVE, hwnd, 0};
                TrackMouseEvent(&tme);
                tracking = true;
            }

            int px = GET_X_LPARAM(lParam);

            if (isDraggingScrubber) {
                Settings settings = GetSettingsSnapshot();
                SharedState state;
                {
                    std::lock_guard lock(g_stateMutex);
                    state = g_state;
                }

                RECT rcClient;
                GetClientRect(hwnd, &rcClient);
                float pillW = static_cast<float>(rcClient.right - rcClient.left) - kRenderPadX * 2.0f;
                float pillCenterX = kRenderPadX + pillW * 0.5f;
                float unscaledX = pillCenterX + (px - pillCenterX) / settings.sizeScale;
                float unscaledLeft = pillCenterX - (pillW / settings.sizeScale) * 0.5f;
                float unscaledRight = pillCenterX + (pillW / settings.sizeScale) * 0.5f;

                float barLeft = unscaledLeft + 60.0f;
                float barRight = unscaledRight - 62.0f;
                if (barRight > barLeft && state.media.endTicks > 0) {
                    float pct = Clamp((unscaledX - barLeft) / (barRight - barLeft), 0.0f, 1.0f);
                    int64_t targetTicks = static_cast<int64_t>(pct * state.media.endTicks);
                    
                    try {
                        auto sessionManager = winrt::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager::RequestAsync().get();
                        if (sessionManager) {
                            auto session = sessionManager.GetCurrentSession();
                            if (session) {
                                session.TryChangePlaybackPositionAsync(targetTicks);
                            }
                        }
                    } catch (...) {}
                }
            }
            return 0;
        }
        case WM_MOUSELEAVE: {
            tracking = false;
            isDraggingScrubber = false;
            g_pressedMediaButton = -1;
            return 0;
        }
        case WM_LBUTTONDOWN: {
            int px = GET_X_LPARAM(lParam);
            int py = GET_Y_LPARAM(lParam);

            Settings settings = GetSettingsSnapshot();
            SharedState state;
            {
                std::lock_guard lock(g_stateMutex);
                state = g_state;
            }

            RECT rcClient;
            GetClientRect(hwnd, &rcClient);
            float pillW = static_cast<float>(rcClient.right - rcClient.left) - kRenderPadX * 2.0f;
            float pillH = static_cast<float>(rcClient.bottom - rcClient.top) - kRenderPadY * 2.0f;
            float pillCenterX = kRenderPadX + pillW * 0.5f;
            float pillCenterY = kRenderPadY + pillH * 0.5f;

            float unscaledX = pillCenterX + (px - pillCenterX) / settings.sizeScale;
            float unscaledY = pillCenterY + (py - pillCenterY) / settings.sizeScale;
            float unscaledLeft = pillCenterX - (pillW / settings.sizeScale) * 0.5f;
            float unscaledRight = pillCenterX + (pillW / settings.sizeScale) * 0.5f;
            float unscaledTop = pillCenterY - (pillH / settings.sizeScale) * 0.5f;

            // Expanded Media Transport Controls & Scrubber Hit-Testing
            if (state.media.available && pillH / settings.sizeScale > 80.0f && Modulo(g_idleTab.load(), 3) == 0) {
                float cy = unscaledTop + 148.0f;
                float cx = pillCenterX;

                // Prev button (kind = 0)
                if (std::hypot(unscaledX - (cx - 64.0f), unscaledY - cy) <= 22.0f) {
                    g_pressedMediaButton = 0;
                    SetCapture(hwnd);
                    return 0;
                }
                // Play/Pause button (kind = 1)
                if (std::hypot(unscaledX - cx, unscaledY - cy) <= 26.0f) {
                    g_pressedMediaButton = 1;
                    SetCapture(hwnd);
                    return 0;
                }
                // Next button (kind = 2)
                if (std::hypot(unscaledX - (cx + 64.0f), unscaledY - cy) <= 22.0f) {
                    g_pressedMediaButton = 2;
                    SetCapture(hwnd);
                    return 0;
                }

                // Scrubber bar
                float scrubberY = unscaledTop + 114.0f;
                float barLeft = unscaledLeft + 60.0f;
                float barRight = unscaledRight - 62.0f;
                if (unscaledY >= scrubberY - 14.0f && unscaledY <= scrubberY + 14.0f &&
                    unscaledX >= barLeft - 6.0f && unscaledX <= barRight + 6.0f) {
                    isDraggingScrubber = true;
                    SetCapture(hwnd);
                    
                    if (barRight > barLeft && state.media.endTicks > 0) {
                        float pct = Clamp((unscaledX - barLeft) / (barRight - barLeft), 0.0f, 1.0f);
                        int64_t targetTicks = static_cast<int64_t>(pct * state.media.endTicks);
                        try {
                            auto sessionManager = winrt::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager::RequestAsync().get();
                            if (sessionManager) {
                                auto session = sessionManager.GetCurrentSession();
                                if (session) {
                                    session.TryChangePlaybackPositionAsync(targetTicks);
                                }
                            }
                        } catch (...) {}
                    }
                    return 0;
                }
            }

            // Collapsed Click-To-Expand
            if (!settings.expandOnHover && (pillH / settings.sizeScale <= 80.0f)) {
                Wh_SetIntValue(L"PinnedExpanded", 1);
                g_layoutDirty = true;
                return 0;
            }

            return 0;
        }
        case WM_LBUTTONUP: {
            if (isDraggingScrubber) {
                isDraggingScrubber = false;
                ReleaseCapture();
                return 0;
            }

            int pressed = g_pressedMediaButton.exchange(-1);
            if (pressed != -1) {
                ReleaseCapture();

                try {
                    auto sessionManager = winrt::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager::RequestAsync().get();
                    if (sessionManager) {
                        auto session = sessionManager.GetCurrentSession();
                        if (session) {
                            if (pressed == 0) session.TrySkipPreviousAsync();
                            else if (pressed == 1) session.TryTogglePlayPauseAsync();
                            else if (pressed == 2) session.TrySkipNextAsync();
                        }
                    }
                } catch (...) {}
                return 0;
            }

            // Click Idle pill to switch tabs
            Settings settings = GetSettingsSnapshot();
            RECT rcClient;
            GetClientRect(hwnd, &rcClient);
            float pillH = static_cast<float>(rcClient.bottom - rcClient.top) - kRenderPadY * 2.0f;
            if (pillH / settings.sizeScale > 80.0f) {
                g_idleTab = Modulo(g_idleTab.load() + 1, 3);
            }
            return 0;
        }
        case WM_RBUTTONUP: {
            POINT pt;
            GetCursorPos(&pt);
            ShowContextMenu(hwnd, pt);
            return 0;
        }
        case WM_LBUTTONDBLCLK: {
            int pinned = Wh_GetIntValue(L"PinnedExpanded", 0);
            Wh_SetIntValue(L"PinnedExpanded", pinned ? 0 : 1);
            g_layoutDirty = true;
            return 0;
        }
        case WM_MBUTTONUP: {
            try {
                auto sessionManager = winrt::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager::RequestAsync().get();
                if (sessionManager) {
                    auto session = sessionManager.GetCurrentSession();
                    if (session) {
                        session.TryTogglePlayPauseAsync();
                    }
                }
            } catch (...) {}
            return 0;
        }
        case WM_MOUSEWHEEL: {
            short delta = GET_WHEEL_DELTA_WPARAM(wParam);
            int tab = g_idleTab.load();
            if (delta > 0) tab = Modulo(tab + 1, 3);
            else if (delta < 0) tab = Modulo(tab - 1 + 3, 3);
            g_idleTab = tab;
            return 0;
        }
        case WM_APP_NEW_EVENT:
            return 0;
        default:
            if (msg == g_shellHookMessage && g_shellHookMessage != 0) {
                if (wParam == HSHELL_WINDOWACTIVATED || wParam == HSHELL_RUDEAPPACTIVATED) {
                    HWND active = reinterpret_cast<HWND>(lParam);
                    if (active && IsWindow(active)) {
                        wchar_t title[256] = {};
                        GetWindowTextW(active, title, ARRAYSIZE(title));
                        std::lock_guard lock(g_stateMutex);
                        g_state.system.foregroundTitle = title;
                    }
                }
                return 0;
            }
            return DefWindowProcW(hwnd, msg, wParam, lParam);
    }
}

// Background Worker Threads

DWORD WINAPI RenderThreadProc(LPVOID) {
    Renderer renderer;
    if (!renderer.Initialize(g_hwnd)) {
        return 1;
    }

    SpringValue widthSpring;
    SpringValue heightSpring;
    SpringValue nudgeSpring;
    widthSpring.Reset(170.0f);
    heightSpring.Reset(36.0f);
    nudgeSpring.Reset(0.0f);

    double lastTime = NowSeconds();
    int frameCount = 0;
    double lastFpsTime = lastTime;
    double lastActiveTime = lastTime;

    while (g_running) {
        double now = NowSeconds();
        float dt = static_cast<float>(now - lastTime);
        lastTime = now;

        Settings settings = GetSettingsSnapshot();
        SharedState state;
        {
            std::lock_guard lock(g_stateMutex);
            state = g_state;
        }

        bool isHover = false;
        POINT pt;
        if (GetCursorPos(&pt)) {
            RECT rcWindow;
            GetWindowRect(g_hwnd, &rcWindow);
            if (PtInRect(&rcWindow, pt)) {
                isHover = true;
                lastActiveTime = now;
            }
        }

        std::vector<IslandKind> activities = ChooseActivities(state, settings, now);
        IslandKind primaryKind = activities.front();
        bool isAlert = (primaryKind == IslandKind::Clipboard ||
                        primaryKind == IslandKind::Notification ||
                        primaryKind == IslandKind::Volume ||
                        primaryKind == IslandKind::CapsLock ||
                        primaryKind == IslandKind::Device ||
                        primaryKind == IslandKind::BatteryLow);

        if (isAlert || (primaryKind == IslandKind::Media && state.media.playing)) {
            lastActiveTime = now;
        }

        bool shouldHide = false;
        if (settings.autoHideIdleSeconds > 0) {
            if (primaryKind == IslandKind::Idle && !isHover && (now - lastActiveTime > settings.autoHideIdleSeconds)) {
                shouldHide = true;
            }
        } else if (settings.autoHideIdleSeconds < 0) {
            if (primaryKind == IslandKind::Idle && !isHover) {
                shouldHide = true;
            }
        }

        bool pinned = Wh_GetIntValue(L"PinnedExpanded", 0) != 0;
        bool expand = (isHover && settings.expandOnHover) || pinned;

        Activity primary;
        primary.kind = primaryKind;

        if (shouldHide) {
            primary.width = 0.0f;
            primary.height = 0.0f;
        } else if (primaryKind == IslandKind::Media) {
            if (expand) {
                primary.width = settings.expandedWidth * settings.sizeScale;
                primary.height = settings.expandedHeight * settings.sizeScale;
            } else {
                primary.width = (settings.collapsedWidth + 40.0f) * settings.sizeScale;
                primary.height = settings.collapsedHeight * settings.sizeScale;
            }
        } else if (isAlert) {
            primary.width = (settings.collapsedWidth + 80.0f) * settings.sizeScale;
            primary.height = (settings.collapsedHeight + 14.0f) * settings.sizeScale;
        } else {
            if (expand) {
                primary.width = settings.expandedWidth * settings.sizeScale;
                primary.height = settings.expandedHeight * settings.sizeScale;
            } else {
                primary.width = settings.collapsedWidth * settings.sizeScale;
                primary.height = settings.collapsedHeight * settings.sizeScale;
            }
        }

        // Spring Physics Update
        widthSpring.Update(primary.width, settings.springStyle, settings.animationSpeed, dt);
        heightSpring.Update(primary.height, settings.springStyle, settings.animationSpeed, dt);
        {
            double lastNudge = g_lastNudgeTime.load();
            float nudgeTarget = 0.0f;
            if (settings.nudgeOffsetPx > 0.1f && (now - lastNudge) < 0.55) {
                float t = static_cast<float>((now - lastNudge) / 0.55);
                float bounce = std::sin(t * 3.14159f) * (1.0f - t);
                nudgeTarget = -settings.nudgeOffsetPx * bounce;
            }
            nudgeSpring.Update(nudgeTarget, SpringStyle::Bouncy, settings.animationSpeed, dt);
        }

        float curW = widthSpring.GetPosition();
        float curH = heightSpring.GetPosition();
        float curNudge = nudgeSpring.GetPosition();

        renderer.Render(state, settings, primary, std::nullopt, curW, curH, curNudge, isHover, pinned, now);

        frameCount++;
        if (now - lastFpsTime >= 1.0) {
            {
                std::lock_guard lock(g_stateMutex);
                g_state.system.renderFps = frameCount;
            }
            frameCount = 0;
            lastFpsTime = now;
            UpdateSystemMetrics();
            UpdateBatteryMetrics();
        }

        int targetFps = settings.targetFps;
        if (settings.lowPowerMode && !isHover && !state.media.playing) {
            targetFps = 30;
        }
        int frameMs = std::max(1, 1000 / targetFps);
        Sleep(frameMs);
    }

    return 0;
}

DWORD WINAPI MediaThreadProc(LPVOID) {
    try {
        winrt::init_apartment();
    } catch (...) {}

    while (g_running) {
        try {
            auto sessionManager = winrt::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager::RequestAsync().get();
            if (sessionManager) {
                auto session = sessionManager.GetCurrentSession();
                if (session) {
                    auto mediaProps = session.TryGetMediaPropertiesAsync().get();
                    auto timeline = session.GetTimelineProperties();
                    auto playbackInfo = session.GetPlaybackInfo();

                    MediaSnapshot snapshot;
                    snapshot.available = true;
                    snapshot.playing = (playbackInfo && playbackInfo.PlaybackStatus() == winrt::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackStatus::Playing);
                    
                    if (mediaProps) {
                        snapshot.title = mediaProps.Title().c_str();
                        snapshot.artist = mediaProps.Artist().c_str();
                        
                        auto thumbnail = mediaProps.Thumbnail();
                        if (thumbnail) {
                            std::vector<uint8_t> bytes = ReadWinRtStreamBytes(thumbnail);
                            if (!bytes.empty()) {
                                DecodeImageBytesToPixels(bytes, &snapshot.art);
                            }
                        }
                    }

                    snapshot.sourceAppUserModelId = session.SourceAppUserModelId().c_str();
                    snapshot.sourceName = FriendlyMediaSourceName(snapshot.sourceAppUserModelId);
                    snapshot.sourceBadge = MediaSourceBadge(snapshot.sourceName);
                    snapshot.sourceIcon = FindMediaSourceIcon(snapshot.sourceAppUserModelId);

                    snapshot.positionTicks = timeline.Position().count();
                    snapshot.endTicks = timeline.EndTime().count();
                    snapshot.lastUpdatedTicks = GetTickCount64();

                    {
                        std::lock_guard lock(g_stateMutex);
                        if (g_state.media.title != snapshot.title || g_state.media.artist != snapshot.artist) {
                            snapshot.artChangedAt = NowSeconds();
                        } else {
                            snapshot.artChangedAt = g_state.media.artChangedAt;
                        }
                        g_state.media = snapshot;
                    }
                } else {
                    std::lock_guard lock(g_stateMutex);
                    g_state.media.available = false;
                    g_state.media.playing = false;
                }
            }
        } catch (...) {}

        Sleep(500);
    }
    return 0;
}

DWORD WINAPI AudioThreadProc(LPVOID) {
    try {
        winrt::init_apartment();
    } catch (...) {}

    ComPtr<IMMDeviceEnumerator> enumerator;
    CoCreateInstance(__uuidof(MMDeviceEnumerator), nullptr, CLSCTX_ALL, IID_PPV_ARGS(&enumerator));
    if (!enumerator) return 1;

    ComPtr<IMMDevice> device;
    enumerator->GetDefaultAudioEndpoint(eRender, eConsole, &device);
    if (!device) return 1;

    ComPtr<IAudioClient> audioClient;
    device->Activate(__uuidof(IAudioClient), CLSCTX_ALL, nullptr, &audioClient);
    if (!audioClient) return 1;

    WAVEFORMATEX* pwfx = nullptr;
    audioClient->GetMixFormat(&pwfx);
    if (!pwfx) return 1;

    audioClient->Initialize(AUDCLNT_SHAREMODE_SHARED, AUDCLNT_STREAMFLAGS_LOOPBACK, 1000000, 0, pwfx, nullptr);
    ComPtr<IAudioCaptureClient> captureClient;
    audioClient->GetService(IID_PPV_ARGS(&captureClient));
    audioClient->Start();

    while (g_running) {
        UINT32 nextPacketSize = 0;
        HRESULT hr = captureClient->GetNextPacketSize(&nextPacketSize);
        if (SUCCEEDED(hr) && nextPacketSize > 0) {
            BYTE* data = nullptr;
            UINT32 numFramesRead = 0;
            DWORD flags = 0;
            hr = captureClient->GetBuffer(&data, &numFramesRead, &flags, nullptr, nullptr);
            if (SUCCEEDED(hr)) {
                if (!(flags & AUDCLNT_BUFFERFLAGS_SILENT)) {
                    PushAudioChunks(data, numFramesRead, pwfx);
                }
                captureClient->ReleaseBuffer(numFramesRead);
            }
        }
        Sleep(15);
    }

    if (pwfx) CoTaskMemFree(pwfx);
    return 0;
}

DWORD WINAPI WeatherThreadProc(LPVOID) {
    while (g_running) {
        std::wstring cityQuery;
        bool isFahrenheit = false;
        {
            std::lock_guard lock(g_settingsMutex);
            cityQuery = g_settings.weatherCity;
            isFahrenheit = g_settings.weatherFahrenheit;
        }

        std::wstring path = L"/";
        if (!cityQuery.empty()) path += cityQuery;
        path += isFahrenheit ? L"?format=j1&u" : L"?format=j1&m";

        std::string json;
        if (HttpGet(L"wttr.in", path, json)) {
            WeatherSnapshot snap;
            snap.hasData = true;
            snap.lastUpdated = NowSeconds();

            auto FindJsonValue = [](const std::string& j, const std::string& key) -> std::string {
                size_t p = j.find("\"" + key + "\"");
                if (p == std::string::npos) return "";
                p = j.find(":", p);
                if (p == std::string::npos) return "";
                size_t valStart = j.find_first_not_of(" \t\r\n\"", p + 1);
                if (valStart == std::string::npos) return "";
                size_t valEnd = j.find_first_of(",}\"\r\n", valStart);
                if (valEnd == std::string::npos) return "";
                return j.substr(valStart, valEnd - valStart);
            };

            std::string tempStr = isFahrenheit ? FindJsonValue(json, "temp_F") : FindJsonValue(json, "temp_C");
            if (!tempStr.empty()) snap.temperature = static_cast<float>(atof(tempStr.c_str()));

            std::string codeStr = FindJsonValue(json, "weatherCode");
            if (!codeStr.empty()) snap.weatherCode = atoi(codeStr.c_str());

            std::string descStr = FindJsonValue(json, "value");
            if (!descStr.empty()) snap.weatherDesc = std::wstring(descStr.begin(), descStr.end());

            std::string windStr = isFahrenheit ? FindJsonValue(json, "windspeedMiles") : FindJsonValue(json, "windspeedKmph");
            if (!windStr.empty()) snap.windSpeed = std::wstring(windStr.begin(), windStr.end());

            std::string windDirStr = FindJsonValue(json, "winddir16Point");
            if (!windDirStr.empty()) snap.windDir = std::wstring(windDirStr.begin(), windDirStr.end());

            std::string humStr = FindJsonValue(json, "humidity");
            if (!humStr.empty()) snap.humidity = std::wstring(humStr.begin(), humStr.end());

            std::string feelsStr = isFahrenheit ? FindJsonValue(json, "FeelsLikeF") : FindJsonValue(json, "FeelsLikeC");
            if (!feelsStr.empty()) snap.feelsLike = std::wstring(feelsStr.begin(), feelsStr.end());

            std::string areaStr = FindJsonValue(json, "areaName");
            if (!areaStr.empty()) snap.city = std::wstring(areaStr.begin(), areaStr.end());
            else snap.city = cityQuery.empty() ? L"Current Location" : cityQuery;

            {
                std::lock_guard lock(g_stateMutex);
                g_state.weather = snap;
            }
        }

        int mins = 10;
        {
            std::lock_guard lock(g_settingsMutex);
            mins = g_settings.weatherUpdateMinutes;
        }
        DWORD waitMs = static_cast<DWORD>(ClampInt(mins, 5, 60) * 60000);
        WaitForSingleObject(g_settingsChangedEvent, waitMs);
    }
    return 0;
}

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION && (wParam == WM_KEYUP || wParam == WM_SYSKEYUP)) {
        auto* kbd = reinterpret_cast<KBDLLHOOKSTRUCT*>(lParam);
        if (kbd->vkCode == VK_CAPITAL || kbd->vkCode == VK_NUMLOCK) {
            CapsLockSnapshot snap;
            snap.active = true;
            snap.capsOn = (GetKeyState(VK_CAPITAL) & 0x0001) != 0;
            snap.numOn = (GetKeyState(VK_NUMLOCK) & 0x0001) != 0;
            snap.isNumEvent = (kbd->vkCode == VK_NUMLOCK);
            snap.expiresAt = NowSeconds() + GetSettingsSnapshot().capsLockDuration;

            {
                std::lock_guard lock(g_stateMutex);
                g_state.capsLock = snap;
            }
            TriggerNudge();
        }
    }
    return CallNextHookEx(g_keyboardHook, nCode, wParam, lParam);
}

DWORD WINAPI KeyboardThreadProc(LPVOID) {
    g_keyboardHook = SetWindowsHookExW(WH_KEYBOARD_LL, LowLevelKeyboardProc, GetModuleHandleW(nullptr), 0);
    MSG msg;
    while (g_running && GetMessageW(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    if (g_keyboardHook) {
        UnhookWindowsHookEx(g_keyboardHook);
        g_keyboardHook = nullptr;
    }
    return 0;
}

#if AEGIS_CAPSULE_HAS_USER_NOTIFICATION_LISTENER
DWORD WINAPI NotificationThreadProc(LPVOID) {
    try { winrt::init_apartment(); } catch (...) {}
    winrt::Windows::UI::Notifications::Management::UserNotificationListener listener = nullptr;
    try {
        listener = winrt::Windows::UI::Notifications::Management::UserNotificationListener::Current();
    } catch (...) {}
    if (!listener) return 1;

    bool accessGranted = false;
    try { accessGranted = (listener.GetAccessStatus() == winrt::Windows::UI::Notifications::Management::UserNotificationListenerAccessStatus::Allowed); } catch (...) {}
    if (!accessGranted) return 1;

    uint32_t lastSeenId = 0;
    while (g_running) {
        try {
            auto notifications = listener.GetNotificationsAsync(winrt::Windows::UI::Notifications::NotificationKinds::Toast).get();
            if (notifications) {
                uint32_t count = notifications.Size();
                for (uint32_t i = 0; i < count; ++i) {
                    auto notif = notifications.GetAt(i);
                    if (!notif) continue;
                    uint32_t nid = notif.Id();
                    if (nid <= lastSeenId) continue;
                    lastSeenId = nid;

                    auto details = notif.Notification();
                    if (!details) continue;

                    std::wstring appTitle, notifTitle, notifBody;
                    try {
                        if (notif.AppInfo() && notif.AppInfo().DisplayInfo()) {
                            appTitle = notif.AppInfo().DisplayInfo().DisplayName().c_str();
                        }
                    } catch (...) {}

                    auto binding = details.Visual().GetBinding(winrt::Windows::UI::Notifications::KnownNotificationBindings::ToastGeneric());
                    if (binding) {
                        auto headLines = binding.GetTextElements();
                        if (headLines && headLines.Size() > 0) notifTitle = headLines.GetAt(0).Text().c_str();
                        if (headLines && headLines.Size() > 1) notifBody = headLines.GetAt(1).Text().c_str();
                    }

                    BitmapPixels iconPx;
                    try {
                        if (notif.AppInfo() && notif.AppInfo().DisplayInfo()) {
                            auto logo = notif.AppInfo().DisplayInfo().GetLogo(winrt::Windows::Foundation::Size(48.0f, 48.0f));
                            if (logo) {
                                auto bytes = ReadWinRtStreamBytes(logo);
                                if (!bytes.empty()) DecodeImageBytesToPixels(bytes, &iconPx);
                            }
                        }
                    } catch (...) {}

                    Settings s = GetSettingsSnapshot();
                    double dur = s.notificationDuration;
                    NotificationSnapshot snap;
                    snap.active = true;
                    snap.app = appTitle.empty() ? L"Notification" : appTitle;
                    snap.title = notifTitle.empty() ? L"New notification" : notifTitle;
                    snap.body = notifBody;
                    snap.icon = iconPx;
                    snap.expiresAt = NowSeconds() + dur;

                    {
                        std::lock_guard lock(g_stateMutex);
                        g_state.notification = snap;
                    }
                    TriggerNudge();
                    break;
                }
            }
        } catch (...) {}
        Sleep(3000);
    }
    return 0;
}
#endif

void UpdateSystemMetrics() {
    FILETIME idleTime, kernelTime, userTime;
    if (GetSystemTimes(&idleTime, &kernelTime, &userTime)) {
        auto ToInt64 = [](const FILETIME& ft) -> uint64_t {
            return (static_cast<uint64_t>(ft.dwHighDateTime) << 32) | ft.dwLowDateTime;
        };

        uint64_t idle = ToInt64(idleTime) - ToInt64(g_prevIdleTime);
        uint64_t kernel = ToInt64(kernelTime) - ToInt64(g_prevKernelTime);
        uint64_t user = ToInt64(userTime) - ToInt64(g_prevUserTime);
        uint64_t total = kernel + user;

        if (total > 0) {
            int cpu = static_cast<int>((total - idle) * 100 / total);
            std::lock_guard lock(g_stateMutex);
            g_state.system.cpuPercent = ClampInt(cpu, 0, 100);
        }

        g_prevIdleTime = idleTime;
        g_prevKernelTime = kernelTime;
        g_prevUserTime = userTime;
    }

    MEMORYSTATUSEX mem = {};
    mem.dwLength = sizeof(mem);
    if (GlobalMemoryStatusEx(&mem)) {
        std::lock_guard lock(g_stateMutex);
        g_state.system.memoryPercent = static_cast<int>(mem.dwMemoryLoad);
    }

    ULARGE_INTEGER freeBytes, totalBytes;
    if (GetDiskFreeSpaceExW(L"C:\\", &freeBytes, &totalBytes, nullptr) && totalBytes.QuadPart > 0) {
        int freePct = static_cast<int>(freeBytes.QuadPart * 100 / totalBytes.QuadPart);
        std::lock_guard lock(g_stateMutex);
        g_state.system.diskFreePercent = freePct;
    }

    int gpu = GetGpuUsage();
    {
        std::lock_guard lock(g_stateMutex);
        g_state.system.gpuPercent = gpu;
    }

    UpdatePrivacyIndicators();
}

void UpdateBatteryMetrics() {
    SYSTEM_POWER_STATUS sps;
    if (GetSystemPowerStatus(&sps)) {
        bool charging = (sps.ACLineStatus == 1);
        bool low = (sps.BatteryFlag & 1) || (sps.BatteryLifePercent <= 20 && !charging);
        
        std::lock_guard lock(g_stateMutex);
        g_state.system.charging = charging;
        
        if (sps.BatteryLifePercent <= 100) {
            g_state.battery.percent = sps.BatteryLifePercent;
            g_state.battery.charging = charging;
            g_state.battery.low = low;
            g_state.battery.secondsRemaining = sps.BatteryLifeTime;
        }
    }
}

// Windhawk Module Lifecycle

void WhTool_ModInit() {
    g_running = true;
    g_stopEvent = CreateEventW(nullptr, TRUE, FALSE, nullptr);
    g_settingsChangedEvent = CreateEventW(nullptr, FALSE, FALSE, nullptr);

    LoadSettings();

    WNDCLASSEXW wc = {};
    wc.cbSize = sizeof(wc);
    wc.lpfnWndProc = OverlayWndProc;
    wc.hInstance = GetModuleHandleW(nullptr);
    wc.lpszClassName = kWindowClass;
    wc.hCursor = LoadCursorW(nullptr, IDC_ARROW);
    RegisterClassExW(&wc);

    g_hwnd = CreateWindowExW(
        WS_EX_LAYERED | WS_EX_TOPMOST | WS_EX_TOOLWINDOW | WS_EX_NOACTIVATE,
        kWindowClass, L"aegisCapsule",
        WS_POPUP, 0, 0, 520, 140,
        nullptr, nullptr, wc.hInstance, nullptr);

    if (g_hwnd) {
        EnableBlurBehind(g_hwnd);
        ShowWindow(g_hwnd, SW_SHOWNOACTIVATE);
        UpdateWindow(g_hwnd);
        g_shellHookMessage = RegisterWindowMessageW(L"SHELLHOOK");
        RegisterShellHookWindow(g_hwnd);
    }

    g_renderThread = CreateThread(nullptr, 0, RenderThreadProc, nullptr, 0, nullptr);
    g_mediaThread = CreateThread(nullptr, 0, MediaThreadProc, nullptr, 0, nullptr);
    g_audioThread = CreateThread(nullptr, 0, AudioThreadProc, nullptr, 0, nullptr);
    g_weatherThread = CreateThread(nullptr, 0, WeatherThreadProc, nullptr, 0, nullptr);
    g_keyboardThread = CreateThread(nullptr, 0, KeyboardThreadProc, nullptr, 0, &g_keyboardThreadId);
#if AEGIS_CAPSULE_HAS_USER_NOTIFICATION_LISTENER
    g_notificationThread = CreateThread(nullptr, 0, NotificationThreadProc, nullptr, 0, nullptr);
#endif
}

void WhTool_ModSettingsChanged() {
    LoadSettings();
    if (g_hwnd) EnableBlurBehind(g_hwnd);
    g_layoutDirty = true;
}

void WhTool_ModUninit() {
    g_running = false;
    if (g_stopEvent) SetEvent(g_stopEvent);
    if (g_settingsChangedEvent) SetEvent(g_settingsChangedEvent);

    if (g_keyboardThreadId) {
        PostThreadMessageW(g_keyboardThreadId, WM_QUIT, 0, 0);
    }

    HANDLE threads[] = {g_renderThread, g_mediaThread, g_audioThread, g_weatherThread, g_keyboardThread
#if AEGIS_CAPSULE_HAS_USER_NOTIFICATION_LISTENER
                         , g_notificationThread
#endif
    };
    for (HANDLE t : threads) {
        if (t) {
            WaitForSingleObject(t, 1000);
            CloseHandle(t);
        }
    }

    if (g_hwnd) {
        DeregisterShellHookWindow(g_hwnd);
        DestroyWindow(g_hwnd);
        g_hwnd = nullptr;
    }

    UnregisterClassW(kWindowClass, GetModuleHandleW(nullptr));

    if (g_stopEvent) CloseHandle(g_stopEvent);
    if (g_settingsChangedEvent) CloseHandle(g_settingsChangedEvent);
    if (g_gpuQuery) {
        PdhCloseQuery(g_gpuQuery);
        g_gpuQuery = NULL;
    }
}

} // namespace

// Windhawk Entry Points

BOOL Wh_ModInit() {
    Wh_Log(L"aegisCapsule: Initializing module...");
    return TRUE;
}

void Wh_ModAfterInit() {
    Wh_Log(L"aegisCapsule: Starting overlay engine...");
    WhTool_ModInit();
}

void Wh_ModSettingsChanged() {
    Wh_Log(L"aegisCapsule: Settings updated.");
    WhTool_ModSettingsChanged();
}

void Wh_ModUninit() {
    Wh_Log(L"aegisCapsule: Shutting down module.");
    WhTool_ModUninit();
}
