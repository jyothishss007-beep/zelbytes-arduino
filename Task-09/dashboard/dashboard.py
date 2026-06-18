import streamlit as st
import requests
import pandas as pd
from datetime import datetime

# =========================
# CONFIG
# =========================

API_KEY = "YOUR_API_KEY"

URL = "https://careers.zelbytes.com/api/iot-lab/v1/telemetry/latest"

ESP32_IP = "YOUR_ESP32_IP"

headers = {
    "X-Iot-Lab-Key": API_KEY
}

# =========================
# PAGE
# =========================

st.set_page_config(
    page_title="Soil Moisture Dashboard",
    layout="wide"
)

st.title("🌱 Soil Moisture Dashboard")

# =========================
# GET LATEST DATA
# =========================

try:

    response = requests.get(URL, headers=headers)

    if response.status_code == 200:

        data = response.json()

        soil = data["latest"]["soil_moisture_pct"]

        st.metric(
            "Soil Moisture (%)",
            f"{soil}%"
        )

        st.progress(int(soil))

        if soil < 30:
            st.error("🔴 Dry Soil")

        elif soil < 70:
            st.warning("🟡 Moderate Moisture")

        else:
            st.success("🟢 Good Moisture")

        # =====================
        # SAVE LOG
        # =====================

        log = pd.DataFrame({
            "Time": [datetime.now().strftime("%H:%M:%S")],
            "Soil Moisture (%)": [soil]
        })

        try:
            old = pd.read_csv("sample_log.csv")
            new = pd.concat([old, log])
            new.to_csv("sample_log.csv", index=False)

        except:
            log.to_csv("sample_log.csv", index=False)

except:
    st.error("Unable to fetch Zelbytes data")

# =========================
# RELAY CONTROL
# =========================

st.divider()

st.subheader("🔌 Relay Control")

col1, col2 = st.columns(2)

with col1:

    if st.button("🟢 Relay ON"):

        try:

            r = requests.get(
                f"http://{ESP32_IP}/on",
                timeout=5
            )

            st.success(r.text)

        except Exception as e:

            st.error(f"ESP32 Error : {e}")

with col2:

    if st.button("🔴 Relay OFF"):

        try:

            r = requests.get(
                f"http://{ESP32_IP}/off",
                timeout=5
            )

            st.success(r.text)

        except Exception as e:

            st.error(f"ESP32 Error : {e}")

if st.button("📊 Check Relay Status"):

    try:

        r = requests.get(
            f"http://{ESP32_IP}/status",
            timeout=5
        )

        if r.text.strip() == "ON":

            st.success("Relay is ON")

        else:

            st.warning("Relay is OFF")

    except Exception as e:

        st.error(f"ESP32 Error : {e}")

# =========================
# PREVIOUS LOGS
# =========================

st.divider()

st.subheader("📋 Previous Logs")

try:

    logs = pd.read_csv("sample_log.csv")

    st.dataframe(
        logs.tail(20),
        use_container_width=True
    )

except:

    st.info("No logs available")

# =========================
# HISTORY CHART
# =========================

st.divider()

st.subheader("📈 Soil Moisture History")

try:

    logs = pd.read_csv("sample_log.csv")

    st.line_chart(
        logs["Soil Moisture (%)"]
    )

except:

    st.info("No chart data available")
