const char PAGE_MAIN[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
    <head>
        <title>Grow Tracker</title>
        <meta http-equiv="content-type" content="text/html" ; charset="utf-8" />
        <script src="https://cdn.tailwindcss.com"></script>
    </head>
    <body class="py-32 text-4xl lg:py-16 bg-slate-100">
        <div class="flex flex-col w-full">
            <div class="mx-auto text-center">
                <h1
                    class="mb-2 font-semibold tracking-tight text-gray-900 text-pretty text-9xl lg:text-balance"
                >
                    Grow Tracker
                </h1>
                <h2 class="mb-20 font-semibold lg:mb-10 text-sky-600">
                    (made by Luca Hoffmann)
                </h2>
                <p class="mb-6 text-gray-600 lg:mb-3">
                    Alle deine Daten auf einen Blick.
                </p>
                <a href="https://www.growtracker.io" target="_blank">
                    <button
                        class="px-3 py-1 mb-12 font-bold rounded lg:mb-6 bg-none text-sky-600 ring ring-sky-500 hover:bg-sky-500 hover:text-white"
                    >
                        www.growtracker.io
                    </button>
                </a>
            </div>
            <div class="max-w-2xl mx-auto mt-20 lg:max-w-7xl">
                <dl
                    class="grid max-w-xl grid-cols-1 gap-16 lg:max-w-none lg:grid-cols-2"
                >
                    <div class="relative pl-36">
                        <dt class="text-5xl font-semibold text-gray-900">
                            <div
                                class="absolute top-0 left-0 flex items-center justify-center rounded-lg bg-sky-600"
                            >
                                <svg
                                    class="m-2 text-white size-28"
                                    fill="none"
                                    viewBox="0 0 24 24"
                                    stroke-width="1.5"
                                    stroke="currentColor"
                                    aria-hidden="true"
                                    data-slot="icon"
                                >
                                    <path
                                        d="M8 15.9998C7.44772 15.9998 7 16.4475 7 16.9998C7 17.5521 7.44772 17.9998 8 17.9998C8.55228 17.9998 9 17.5521 9 16.9998C9 16.4475 8.55228 15.9998 8 15.9998ZM8 15.9998L8.00707 12M8 16.9998L8.00707 17.0069M20 5C20 6.10457 19.1046 7 18 7C16.8954 7 16 6.10457 16 5C16 3.89543 16.8954 3 18 3C19.1046 3 20 3.89543 20 5ZM12 16.9998C12 19.209 10.2091 20.9998 8 20.9998C5.79086 20.9998 4 19.209 4 16.9998C4 15.9854 4.37764 15.0591 5 14.354L5 6C5 4.34315 6.34315 3 8 3C9.65685 3 11 4.34315 11 6V14.354C11.6224 15.0591 12 15.9854 12 16.9998Z"
                                        stroke-linecap="round"
                                        stroke-linejoin="round"
                                    />
                                </svg>
                            </div>
                            Temperatur
                        </dt>
                        <dd
                            class="mt-2 text-[#9afe2e] bg-black ring ring-sky-600 p-2"
                        >
                            <span id="Temperature">-</span> °C
                        </dd>
                    </div>
                    <div class="relative pl-36">
                        <dt class="text-5xl font-semibold text-gray-900">
                            <div
                                class="absolute top-0 left-0 flex items-center justify-center rounded-lg bg-sky-600"
                            >
                                <svg
                                    class="m-2 text-white size-28"
                                    fill="currentColor"
                                    viewBox="0 0 24 24"
                                    aria-hidden="true"
                                    data-slot="icon"
                                >
                                    <path
                                        d="M15.0066 3.25608C16.8483 2.85737 19.1331 2.8773 22.2423 3.65268C22.7781 3.78629 23.1038 4.32791 22.9699 4.86241C22.836 5.39691 22.2931 5.7219 21.7573 5.58829C18.8666 4.86742 16.9015 4.88747 15.4308 5.20587C13.9555 5.52524 12.895 6.15867 11.7715 6.84363L11.6874 6.89494C10.6044 7.55565 9.40515 8.28729 7.82073 8.55069C6.17734 8.82388 4.23602 8.58235 1.62883 7.54187C1.11607 7.33724 0.866674 6.75667 1.0718 6.24513C1.27692 5.73359 1.85889 5.48479 2.37165 5.68943C4.76435 6.6443 6.32295 6.77699 7.492 6.58265C8.67888 6.38535 9.58373 5.83916 10.7286 5.14119C11.855 4.45445 13.1694 3.6538 15.0066 3.25608Z"
                                    />
                                    <path
                                        d="M22.2423 7.64302C19.1331 6.86765 16.8483 6.84772 15.0066 7.24642C13.1694 7.64415 11.855 8.44479 10.7286 9.13153C9.58373 9.8295 8.67888 10.3757 7.492 10.573C6.32295 10.7673 4.76435 10.6346 2.37165 9.67977C1.85889 9.47514 1.27692 9.72393 1.0718 10.2355C0.866674 10.747 1.11607 11.3276 1.62883 11.5322C4.23602 12.5727 6.17734 12.8142 7.82073 12.541C9.40515 12.2776 10.6044 11.546 11.6874 10.8853L11.7715 10.834C12.895 10.149 13.9555 9.51558 15.4308 9.19621C16.9015 8.87781 18.8666 8.85777 21.7573 9.57863C22.2931 9.71224 22.836 9.38726 22.9699 8.85275C23.1038 8.31825 22.7781 7.77663 22.2423 7.64302Z"
                                    />
                                    <path
                                        fill-rule="evenodd"
                                        clip-rule="evenodd"
                                        d="M18.9998 10.0266C18.6526 10.0266 18.3633 10.2059 18.1614 10.4772C18.0905 10.573 17.9266 10.7972 17.7089 11.111C17.4193 11.5283 17.0317 12.1082 16.6424 12.7555C16.255 13.3996 15.8553 14.128 15.5495 14.8397C15.2567 15.5213 14.9989 16.2614 14.9999 17.0117C15.0006 17.2223 15.0258 17.4339 15.0604 17.6412C15.1182 17.9872 15.2356 18.4636 15.4804 18.9521C15.7272 19.4446 16.1131 19.9674 16.7107 20.3648C17.3146 20.7664 18.0748 21 18.9998 21C19.9248 21 20.685 20.7664 21.2888 20.3648C21.8864 19.9674 22.2724 19.4446 22.5192 18.9522C22.764 18.4636 22.8815 17.9872 22.9393 17.6413C22.974 17.4337 22.9995 17.2215 22.9998 17.0107C23.0001 16.2604 22.743 15.5214 22.4501 14.8397C22.1444 14.128 21.7447 13.3996 21.3573 12.7555C20.968 12.1082 20.5803 11.5283 20.2907 11.111C20.073 10.7972 19.909 10.573 19.8382 10.4772C19.6363 10.2059 19.3469 10.0266 18.9998 10.0266ZM20.6119 15.6257C20.3552 15.0281 20.0049 14.3848 19.6423 13.782C19.4218 13.4154 19.2007 13.0702 18.9998 12.7674C18.7989 13.0702 18.5778 13.4154 18.3573 13.782C17.9948 14.3848 17.6445 15.0281 17.3878 15.6257L17.3732 15.6595C17.1965 16.0704 16.9877 16.5562 17.0001 17.0101C17.0121 17.3691 17.1088 17.7397 17.2693 18.0599C17.3974 18.3157 17.574 18.5411 17.8201 18.7048C18.06 18.8643 18.4248 19.0048 18.9998 19.0048C19.5748 19.0048 19.9396 18.8643 20.1795 18.7048C20.4256 18.5411 20.6022 18.3156 20.7304 18.0599C20.8909 17.7397 20.9876 17.3691 20.9996 17.01C21.0121 16.5563 20.8032 16.0705 20.6265 15.6597L20.6119 15.6257Z"
                                    />
                                    <path
                                        d="M14.1296 11.5308C14.8899 11.2847 15.4728 12.076 15.1153 12.7892C14.952 13.1151 14.7683 13.3924 14.4031 13.5214C13.426 13.8666 12.6166 14.3527 11.7715 14.8679L11.6874 14.9192C10.6044 15.5799 9.40516 16.3115 7.82074 16.5749C6.17735 16.8481 4.23604 16.6066 1.62884 15.5661C1.11608 15.3615 0.866688 14.7809 1.07181 14.2694C1.27694 13.7578 1.8589 13.509 2.37167 13.7137C4.76436 14.6685 6.32297 14.8012 7.49201 14.6069C8.67889 14.4096 9.58374 13.8634 10.7286 13.1654C11.8166 12.5021 12.9363 11.9171 14.1296 11.5308Z"
                                    />
                                </svg>
                            </div>
                            Luftfeuchtigkeit
                        </dt>
                        <dd
                            class="mt-2 text-[#9afe2e] bg-black ring ring-sky-600 p-2"
                        >
                            <span id="Humidity">-</span> %
                        </dd>
                    </div>
                    <div class="relative pl-36">
                        <dt class="text-5xl font-semibold text-gray-900">
                            <div
                                class="absolute top-0 left-0 flex items-center justify-center rounded-lg bg-sky-600"
                            >
                                <svg
                                    class="m-2 text-white size-28"
                                    fill="currentColor"
                                    viewBox="0 0 32 32"
                                    aria-hidden="true"
                                    data-slot="icon"
                                >
                                    <path
                                        d="M24.5,30a5.202,5.202,0,0,1-4.626-8.08L23.49,16.5382a1.217,1.217,0,0,1,2.02,0L29.06,21.8154A5.4921,5.4921,0,0,1,30,24.751,5.385,5.385,0,0,1,24.5,30Zm0-11.38-2.9356,4.3672A3.2079,3.2079,0,0,0,24.5,28,3.3855,3.3855,0,0,0,28,24.751a3.4354,3.4354,0,0,0-.63-1.867Z"
                                        transform="translate(0 0)"
                                    />
                                    <path
                                        d="M11,16V11h1a4.0045,4.0045,0,0,0,4-4V4H13a3.9779,3.9779,0,0,0-2.7468,1.1067A6.0034,6.0034,0,0,0,5,2H2V5a6.0066,6.0066,0,0,0,6,6H9v5H2v2H16V16ZM13,6h1V7a2.002,2.002,0,0,1-2,2H11V8A2.002,2.002,0,0,1,13,6ZM8,9A4.0045,4.0045,0,0,1,4,5V4H5A4.0045,4.0045,0,0,1,9,8V9Z"
                                        transform="translate(0 0)"
                                    />
                                    <rect x="2" y="21" width="14" height="2" />
                                    <rect x="2" y="26" width="14" height="2" />
                                    <rect fill="none" width="32" height="32" />
                                </svg>
                            </div>
                            Bodenfeuchtigkeit
                        </dt>
                        <dd
                            class="mt-2 text-[#9afe2e] bg-black ring ring-sky-600 p-2 grid grid-cols-2 gap-y-3"
                        >
                            <p>A: <span id="Soil_1">-</span> %</p>
                            <p>B: <span id="Soil_2">-</span> %</p>
                            <p>C: <span id="Soil_3">-</span> %</p>
                            <p>D: <span id="Soil_4">-</span> %</p>
                            <p>E: <span id="Soil_5">-</span> %</p>
                            <p>F: <span id="Soil_6">-</span> %</p>
                            <p>G: <span id="Soil_7">-</span> %</p>
                            <p>H: <span id="Soil_8">-</span> %</p>
                        </dd>
                    </div>
                </dl>
            </div>
        </div>

        <script>
            setInterval(function () {
                getSensorData();
            }, 1000);
            function getSensorData() {
                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange = function () {
                    if (this.readyState == 4 && this.status == 200) {
                        const data = JSON.parse(this.response).data;

                        const temperature = data.find(
                            (item) => item.type === "Temperature"
                        );
                        const humidity = data.find(
                            (item) => item.type === "Humidity"
                        );
                        const soil = data.find((item) => item.type === "Soil");

                        document.getElementById("Temperature").innerHTML =
                            temperature.value;
                        document.getElementById("Humidity").innerHTML =
                            humidity.value;

                        soil.sensors.forEach((sensor) => {
                            document.getElementById(
                                "Soil_" + sensor.number
                            ).innerHTML = sensor.value;
                        });
                    }
                };
                xhttp.open("GET", "sensorData", true);
                xhttp.send();
            }
        </script>
    </body>
</html>
)=====";